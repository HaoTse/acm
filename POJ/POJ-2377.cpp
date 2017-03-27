#include <cstdio>
#include <algorithm>

using namespace std;

struct EDGE{
    int a, b;
    int len;
}edge[20003];

int p[1003];

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
    return a.len > b.len;
}

int main(){
    int N, M, A, B, C;

    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].len);
    }

    sort(edge, edge + M, cmp);

    int ans = 0, cnt = 0;
    ini(N);
    for(int i = 0; i < M; i++){
        if(Find(edge[i].a) != Find(edge[i].b)){
            Union(edge[i].a, edge[i].b);
            ans += edge[i].len;
            cnt++;
        }
    }
    if(cnt != N - 1) ans = -1;
    printf("%d\n", ans);

    return 0;
}
