#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int dfn[105], low[105];
vector<int> node[105];
map<string, int> Map;
string str_record[105];
vector<string> ans;

int cnt_dfn = 0, cnt_cutV = 0;
void dfs(int p, int n){
    bool cut_vertex = false;
    int child = 0;
    low[n] = dfn[n] = ++cnt_dfn;
    for(int i = 0; i < node[n].size(); i++){
        if(!dfn[node[n][i]]){
            dfs(n, node[n][i]);
            low[n] = (low[n] < low[node[n][i]]) ? low[n] : low[node[n][i]];
            if(low[node[n][i]] >= dfn[n])
                cut_vertex = true;
            child++;
        }
        else if(node[n][i] != p){
            low[n] = (low[n] < dfn[node[n][i]]) ? low[n] : dfn[node[n][i]];
        }
    }
    if((child > 1 || p != -1) && cut_vertex){
        cnt_cutV++;
        ans.push_back(str_record[n]);
    }
}

int main(){
    int N, R, cnt_in;
    int Case = 0;
    char buf1[35], buf2[35];

    while(scanf("%d", &N) && N){

        //init
        Map.clear();
        ans.clear();
        for(int i = 0; i <= N; i++){
            node[i].clear();
            dfn[i] = low[i] = 0;
        }
        cnt_in = 0;

        //input
        for(int i = 0; i < N; i++){
            scanf(" %s", buf1);
            str_record[++cnt_in] = buf1;
            Map[buf1] = cnt_in;
        }
        scanf(" %d", &R);
        for(int i = 0; i < R; i++){
            scanf(" %s %s", buf1, buf2);
            node[Map[buf1]].push_back(Map[buf2]);
            node[Map[buf2]].push_back(Map[buf1]);
        }

        //SCC
        cnt_dfn = cnt_cutV = 0;
        for(int i = 1; i <= N; i++)
            if(!dfn[i]) dfs(-1, i);

        //output
        sort(ans.begin(), ans.end());
        if(Case) puts("");
        printf("City map #%d: %d camera(s) found\n", ++Case, cnt_cutV);
        for(auto out: ans){
            printf("%s\n", out.c_str());
        }
    }
    return 0;
}
