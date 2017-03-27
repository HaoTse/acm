#include <cstdio>
#include <algorithm>

using namespace std;

int p[50005];

void ini(int n){
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int Find(int x){
    return (p[x] == x) ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y){
    p[Find(x)] = Find(y);
}

int main(){
    int n, m, x, y;
    int Case = 0, ans = 1;

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0)
            break;

        Case++;
        ans = 1;
        ini(n);

        while(m--){
            scanf("%d %d", &x, &y);
            Union(x, y);
        }

        for(int i = n; i > 0; i--){
            p[i] = Find(p[i]);
        }

        sort(p + 1, p + 1 + n);
        for(int i = 2; i <= n; i++){
            if(p[i] != p[i - 1])
                ans++;
        }
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
