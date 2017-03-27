#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

int dfn[105], low[105];
vector<int> node[105];

int cnt_dfn = 0, ans = 0;
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
    if((child > 1 || p != -1) && cut_vertex)
        ans++;
}

int main(){
    int N;
    char buf[500];
    char *tok;

    while(scanf("%d\n", &N) && N){

        for(int i = 0; i <= N; i++){
            node[i].clear();
            dfn[i] = low[i] = 0;
        }

        int s, u;
        do{
            gets(buf);
            s = 0;
            for(tok = strtok(buf, " "); tok != NULL; tok = strtok(NULL, " ")){
                if(s){
                    u = atoi(tok);
                    node[s].push_back(u);
                    node[u].push_back(s);
                }
                else
                    s = atoi(tok);
            }
        } while(s);

        cnt_dfn = 0;
        ans = 0;
        dfs(-1, 1);
        printf("%d\n", ans);
    }
    return 0;
}
