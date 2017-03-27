#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct EDGE{
    int a, b;
    int len;
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
    return a.len > b.len;
}

int main(){
    int Case, n, m;

    scanf("%d", &Case);
    for(int c = 1; c <= Case; c++){
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
            scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].len);

        sort(edge, edge + m, cmp);

        int ans = 0, cnt = 0;
        ini(n);
        for(int i = 0; i < m; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                cnt++;
            }
            if(cnt + 1 == n){
                ans = edge[i].len;
                break;
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
    return 0;
}
