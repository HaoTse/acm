#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct EDGE{
    int a, b;
    int len;
}edge[250003];

int p[503];

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

        int num_edge = 0, length;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &length);
                if(i == j) continue;
                edge[num_edge].a = i;
                edge[num_edge].b = j;
                edge[num_edge++].len = length;
            }
        }

        sort(edge, edge + num_edge, cmp);

        int ans = 0;
        ini(n + 1);
        for(int i = 0; i < num_edge; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                ans = (ans > edge[i].len) ? ans : edge[i].len;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
