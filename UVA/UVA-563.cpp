#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 0x3f3f3f3f
#define N 5500

using namespace std;

typedef int Graph[N][N];
Graph cap, flow;
bool visit[N];
int pre[N];
int bottleneck[N];
vector<int> node[N]; // without it will TLE

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

        for(int j : node[i]){
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
    int Case, s, a, b;

    scanf("%d", &Case);
    while(Case--){
        scanf("%d %d %d", &s, &a, &b);
        int src = 1, sink = (s * s + a + 1) * 2;

        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for(int i = src; i <= sink; i++)
            node[i].clear();

        for(int i = 0; i < b; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            cap[src][(x * s + y) * 2] = 1;
            node[src].push_back((x * s + y) * 2);
        }

        // graph
        for(int i = 1; i <= s; i++){
            for(int j = 1; j <= a; j++){
                int u_ = (i * s + j) * 2 + 1;

                cap[u_ - 1][u_] = 1;
                cap[u_][((i - 1) * s + j) * 2] = 1;
                cap[u_][((i + 1) * s + j) * 2] = 1;
                cap[u_][(i * s + j - 1) * 2] = 1;
                cap[u_][(i * s + j + 1) * 2] = 1;

                node[u_ - 1].push_back(u_);
                node[u_].push_back(((i - 1) * s + j) * 2);
                node[u_].push_back(((i + 1) * s + j) * 2);
                node[u_].push_back((i * s + j - 1) * 2);
                node[u_].push_back((i * s + j + 1) * 2);

                if(i == 1 || j == 1 || i == s || j == a){
                    cap[u_][sink] = 1;
                    node[u_].push_back(sink);
                }
            }
        }

        (Edmonds_Karp(src, sink) == b) ? puts("possible") : puts("not possible");
    }

    return 0;
}