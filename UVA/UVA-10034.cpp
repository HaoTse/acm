#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct POS{
    double x, y;
}pos[103];

struct EDGE{
    int a, b;
    double len;
}edge[10003];

int p[103];

void ini(int n){
    for(int i = 0; i < n; i++) p[i] = i;
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
    int Case, n;

    scanf("%d", &Case);
    while(Case--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &pos[i].x, &pos[i].y);
        }

        int num_edge = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edge[num_edge].a = i;
                edge[num_edge].b = j;
                edge[num_edge++].len = sqrt(pow(pos[i].x - pos[j].x, 2) + pow(pos[i].y - pos[j].y, 2));
            }
        }

        sort(edge, edge + num_edge, cmp);

        double ans = 0;
        ini(n);
        for(int i = 0; i < num_edge; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                ans += edge[i].len;
            }
        }
        printf("%.2f\n", ans);
        if(Case) printf("\n");
    }
    return 0;
}
