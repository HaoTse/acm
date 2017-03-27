#include <cstdio>
#include <algorithm>

using namespace std;

struct EDGE{
    int a, b;
    int len;
}edge[900];

int p[30];
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
    int N, s, u;
    char buf;

    while(scanf("%d", &N) && N){
        int cnt_edge = 0;
        int cnt;
        for(int i = 0; i < N - 1; i++){
            scanf(" %c%d", &buf, &cnt);
            s = buf - 'A';
            while(cnt--){
                scanf(" %c%d", &buf, &edge[cnt_edge].len);
                edge[cnt_edge].a = s;
                edge[cnt_edge++].b = buf - 'A';
            }
        }

        sort(edge, edge + cnt_edge, cmp);

        int ans = 0;
        ini(N);
        for(int i = 0; i < cnt_edge; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                ans += edge[i].len;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
