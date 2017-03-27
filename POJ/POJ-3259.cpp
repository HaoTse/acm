#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

int dis[1003] = {0};
int N, numEdge;

struct EDGE{
    int u, v, w;
    bool bi;
}edge[2703];

void Relax(int u, int v, int w, bool f){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
    if(f && dis[v] + w < dis[u])
        dis[u] = dis[v] + w;
}

bool BellmanFord(){
    dis[N] = 0;
    for(int i = 1; i < N; i++)
        dis[i] = INF;

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < numEdge; j++)
            Relax(edge[j].u, edge[j].v, edge[j].w, edge[j].bi);

    for(int j = 0; j < numEdge; j++){
        if(dis[edge[j].u] + edge[j].w < dis[edge[j].v])
            return true;
        if(edge[j].bi && dis[edge[j].v] + edge[j].w < dis[edge[j].u])
            return true;
    }
    return false;
}

int main(){
    int F, M, W, S, E, T;
    scanf("%d", &F);
    while(F--){
        scanf("%d %d %d", &N, &M, &W);
        numEdge = M + W;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].bi = true;
        }
        for(int i = M; i < M + W; i++){
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].w *= -1;
            edge[i].bi = false;
        }
        if(BellmanFord())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
