#include <cstdio>
#include <vector>

using namespace std;

int dfn[1003], low[1003];
vector<int> node[1003];

int cnt_dfn = 0, ans = 0;
void dfs(int p, int n){
    bool cut_vertex = false;
    low[n] = dfn[n] = ++cnt_dfn;
    for(int i = 0; i < node[n].size(); i++){
        if(!dfn[node[n][i]]){
            dfs(n, node[n][i]);
            low[n] = (low[n] < low[node[n][i]]) ? low[n] : low[node[n][i]];
            if(low[node[n][i]] > dfn[n]){
                printf("%d %d\n", n, node[n][i]);
                printf("%d %d\n", node[n][i], n);
                cut_vertex = true;
            }
            else
                printf("%d %d\n", n, node[n][i]);
        }
        else if(node[n][i] != p){
            if(dfn[n] >= dfn[node[n][i]])
                printf("%d %d\n", n, node[n][i]);
            low[n] = (low[n] < dfn[node[n][i]]) ? low[n] : dfn[node[n][i]];
        }
    }
}

int main(){
    int n, m;
    int Case = 0;

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0) break;

        for(int i = 0; i <= n; i++){
            node[i].clear();
            dfn[i] = low[i] = 0;
        }

        int s, u;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &s, &u);
            node[s].push_back(u);
            node[u].push_back(s);
        }

        cnt_dfn = 0;
        printf("%d\n\n", ++Case);
        for(int i = 1; i <= n; i++){
            if(!dfn[i])
                dfs(-1, i);
        }
        puts("#");
    }
    return 0;
}

