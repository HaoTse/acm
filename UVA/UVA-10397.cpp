#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct POS{
    int x, y;
}pos[753];

struct EDGE{
    int a, b;
    double len;
}edge[562503];

int p[753];

void ini(int n){
    for(int i = 1; i <= n; i++) p[i] = i;
}

int Find(int x){
    return (p[x] == x) ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y){
    p[Find(x)] = Find(y);
}

bool cmp(EDGE a, EDGE b){
    return a.len < b.len;
}

int main(){
    int N, M;

    while(scanf("%d", &N) != EOF){

        for(int i = 1; i <= N; i++){
            scanf("%d %d", &pos[i].x, &pos[i].y);
        }

        int num_edge = 0;
        for(int i = 1; i <= N; i++){
            for(int j = i + 1; j <= N; j++){
                edge[num_edge].a = i;
                edge[num_edge].b = j;
                edge[num_edge++].len = sqrt(pow(pos[i].x - pos[j].x, 2) + pow(pos[i].y - pos[j].y, 2));
            }
        }

        sort(edge, edge + num_edge, cmp);

        ini(N);
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            int s, u;
            scanf("%d %d", &s, &u);
            Union(s, u);
        }

        double ans = 0;
        for(int i = 0; i < num_edge; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                ans += edge[i].len;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
