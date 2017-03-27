#include <cstdio>

int main(){
    int num, n, m;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        scanf("%d %d", &n, &m);
        printf("Scenario #%d:\n", i);

        if(n % 2 == 0 || m % 2 == 0)
            printf("%.2f\n\n", (float) n * (float) m);
        else
            printf("%.2f\n\n", (float) n * (float) m - 1.0 + 1.414); //sqrt(2.0) == 1.414
    }

    return 0;
}
