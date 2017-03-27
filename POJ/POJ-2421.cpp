#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct EDGE{
    int a, b;
    int len;
}edge[10003];

int p[2003];

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
    int N, Q, len;

    scanf("%d", &N);
    int cnt_edge = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &len);
            if(!len) continue;
            edge[cnt_edge].a = i;
            edge[cnt_edge].b = j;
            edge[cnt_edge++].len = len;
        }
    }
    sort(edge, edge + cnt_edge, cmp);

    scanf("%d", &Q);
    ini(N);
    for(int i = 0; i < Q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    int ans = 0;
    for(int i = 0; i < cnt_edge; i++){
        if(Find(edge[i].a) != Find(Find(edge[i].b))){
            Union(edge[i].a, edge[i].b);
            ans += edge[i].len;
        }
    }
    printf("%d\n", ans);

    return 0;
}
