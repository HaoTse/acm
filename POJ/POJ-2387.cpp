#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

int dis[1003] = {0};
int N, T;

struct EDGE{
    int u, v, w;
}edge[2003];

void Relax(int u, int v, int w){
    if(dis[u] + w < dis[v])
        dis[v] = dis[u] + w;
    if(dis[v] + w < dis[u])
        dis[u] = dis[v] + w;

}

void BellmanFord(){
    dis[N] = 0;
    for(int i = 1; i < N; i++)
        dis[i] = INF;

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < T; j++)
            Relax(edge[j].u, edge[j].v, edge[j].w);
}

int main(){
    scanf("%d %d", &T, &N);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    BellmanFord();
    printf("%d\n", dis[1]);
    return 0;
}
