#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 999999
#define N 250 

using namespace std;

typedef int Graph[N][N];
Graph cap, flow, dis;
bool visit[N];
int pre[N];
int bottleneck[N];
int K, C, M;

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

int Max_Flow(int d){
    int n = K + C;
    int src = n, sink = n + 1;
    memset(flow, 0, sizeof(flow));
    memset(cap, 0, sizeof(cap));

    for(int i = 0; i < K; i++){
        for(int j = K; j < n; j++){
            if(dis[i][j] <= d)
                cap[i][j] = 1;
        }
    }
    for(int i = 0; i < K; i++)
        cap[src][i] = M;
    for(int i = K; i < n; i++)
        cap[i][sink] = 1;
    
    return Edmonds_Karp(src, sink);
}

int main(){

    scanf("%d %d %d", &K, &C, &M);
    int n = K + C;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &dis[i][j]);
            dis[i][j] = (dis[i][j]) ? dis[i][j] : INF;
        }
    }

    // floyd
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    // binary search
    int l = 1, r = INF, mid;
    while(l != r){
        mid = (l + r) / 2;

        int num = Max_Flow(mid);
        if(num >= C) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);

    return 0;
}