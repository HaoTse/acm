#include <cstdio>

#define INF 0x3f3f3f3f

int dis[1003];
int N, M;

struct EDGE{
    int u, v, w;
}edge[2003];

void Relax(int u, int v, int w){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
}

bool BellmanFord(){
    dis[N] = 0;
    for(int i = 1; i < N; i++)
        dis[i] = INF;

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < M; j++)
            Relax(edge[j].u, edge[j].v, edge[j].w);

    for(int j = 0; j < M; j++){
        if(dis[edge[j].u] + edge[j].w < dis[edge[j].v])
            return true;
    }
    return false;
}

int main(){
    int Case;

    scanf("%d", &Case);
    while(Case--){
        scanf("%d%d", &N, &M);
        for(int i = 0; i < M; i++){
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        if(BellmanFord()) puts("possible");
        else puts("not possible");
    }
    return 0;
}
