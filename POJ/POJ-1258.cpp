#include <cstdio>
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
    return a.len < b.len;
}

int main(){
    int N;

    while(scanf("%d", &N) != EOF){
        int cnt_edge = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                edge[cnt_edge].a = i;
                edge[cnt_edge].b = j;
                scanf("%d", &edge[cnt_edge++].len);
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
