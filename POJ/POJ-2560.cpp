#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct POINT{
    double x, y;
}point[753];

struct EDGE{
    int a, b;
    double len;
}edge[562503];

int p[753];

void ini(int n){
    for(int i = 0; i <= n; i++) p[i] = i;
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

    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lf%lf", &point[i].x, &point[i].y);
    }
    int cnt_edge = 0;
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            double len = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
            edge[cnt_edge].a = i;
            edge[cnt_edge].b = j;
            edge[cnt_edge++].len = len;
        }
    }
    ini(N);

    sort(edge, edge + cnt_edge, cmp);

    double ans = 0;
    for(int i = 0; i < cnt_edge; i++){
        if(Find(edge[i].a) != Find(edge[i].b)){
            Union(edge[i].a, edge[i].b);
            ans += edge[i].len;
        }
    }
    printf("%.2f\n", ans);

    return 0;
}
