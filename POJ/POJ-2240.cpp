#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>

using namespace std;

double r[33][33];

int main(){
    int n, m, Case = 1;
    map<string, int> c;
    char buf1[99], buf2[99];
    double rate;

    while(scanf("%d", &n)){
        if(n == 0) break;

        c.clear();
        memset(r, 0, sizeof(r));
        for(int i = 0; i < n; i++) r[i][i] = 1;

        for(int i = 0; i < n; i++){
            scanf("%s", buf1);
            c[buf1] = i;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%s %lf %s", buf1, &rate, buf2);
            int a = c[buf1], b = c[buf2];
            r[a][b] = rate;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(r[i][k] * r[k][j] > r[i][j])
                        r[i][j] = r[i][k] * r[k][j];
                }
            }
        }

        bool f = false;
        for(int i = 0; i < n; i++)
            if(r[i][i] > 1) f = true;
        if(f) printf("Case %d: Yes\n", Case++);
        else printf("Case %d: No\n", Case++);
    }

    return 0;
}
