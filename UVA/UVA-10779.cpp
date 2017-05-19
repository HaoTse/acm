#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

typedef int Graph[40][40];
Graph cap, flow;
bool visit[40];
int pre[40];
int bottleneck[40];

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

        for(int j = 1; j <= t; j++){
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
    int T, n, m;

    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        memset(flow, 0, sizeof(flow));
        memset(cap, 0, sizeof(cap));

        scanf("%d %d", &n, &m);

        int source = 1, sink = n + m + 1;

        for(int i = 1; i <= n; i++){
            int k, ki;
            scanf("%d", &k);
            while(k--){
                scanf("%d", &ki);
                cap[i][n + ki]++;
            }
        }

        for(int i = 1; i <= m; i++){
            cap[n + i][sink] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(cap[i][n + j] == 0)
                    cap[n + j][i] = 1;
                else
                    cap[i][n + j]--;
            }
        }

        printf("Case #%d: %d\n", c, Edmonds_Karp(source, sink));
    }

    return 0;
}