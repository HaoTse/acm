#include <cstdio>

int main(){
    int n, Case = 1;

    while(scanf("%d", &n) && n)
        printf("Case %d: %d\n", Case++, n/2);
    return 0;
}
