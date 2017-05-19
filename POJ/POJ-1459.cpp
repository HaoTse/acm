#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 0x3f3f3f3f
#define N 110

using namespace std;

typedef int Graph[N][N];
Graph cap, flow;
bool visit[N];
int pre[N];
int bottleneck[N];

int BFS(int s, int t){
    memset(visit, false, sizeof(visit));

    queue<int> Q;
    visit[s] = true;
    pre[s] = s;
    bottleneck[s] = INF;
    Q.push(s);

    while(!Q.empty()){
        int i = Q.front();
        Q.pop();

        for(int j = 0; j <= t; j++){
            if(!visit[j] && cap[i][j] - flow[i][j] > 0){
                visit[j] = true;
                pre[j] = i;
                bottleneck[j] = min(bottleneck[i], cap[i][j] - flow[i][j]);
                Q.push(j);

                if(j == t) return bottleneck[t];
            }
        }
    }

    return 0;
}

int Edmonds_Karp(int s, int t){
    int f, df;
    for(f = 0; df = BFS(s, t); f += df){
        for(int i = pre[t], j = t; i != j; i = pre[j = i]){
            flow[i][j] += df;
            flow[j][i] -= df;
        }
    }
    return f;
}

int main(){
    int n, np, nc, m;

    while(scanf("%d", &n) != EOF){
        scanf("%d %d %d", &np, &nc, &m);
        int src = n , sink = n + 1;

        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        for(int i = 0; i < m; i++){
            int u, v, z;
            scanf(" (%d,%d)%d", &u, &v, &z);
            cap[u][v] = z;
        }

        for(int i = 0; i < np; i++){
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[src][u] = z;
        }

        for(int i = 0; i < nc; i++){
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[u][sink] = z;
        }

        printf("%d\n", Edmonds_Karp(src, sink));
    }

    return 0;
}