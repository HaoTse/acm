#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct POS{
    int x, y;
}pos[403];

struct EDGE{
    int a, b;
    double len;
}edge[79803];

int p[403];
map<string, int> m;

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
    int s, c;
    char str1[100], str2[100];

    while(scanf("%d %d", &s, &c)){
        if(s == 0 && c == 0) break;

        m.clear();
        for(int i = 0; i < s; i++){
            scanf("%s", str1);
            m[str1] = i;
        }
        for(int i = 0; i < c; i++){
            int tmp;
            scanf("%s %s %d", str1, str2, &tmp);
            edge[i].a = m[str1];
            edge[i].b = m[str2];
            edge[i].len = tmp;
        }
        scanf("%s", str1);
        sort(edge, edge + c, cmp);

        ini(s);
        int ans = 0, cnt = 0;
        for(int i = 0; i < c; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                ans += edge[i].len;
                if(++cnt == s - 1) break;
            }
        }
        if(cnt == s - 1)
            printf("%d\n", ans);
        else
            puts("Impossible");
    }
    return 0;
}
