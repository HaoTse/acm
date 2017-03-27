#include <cstdio>

int main(){
    int num;
    float c = 0.0;
    float up = 0.0;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        scanf("%f %f", &c, &up);
        c += up * 5.0 / 9.0;
        printf("Case %d: %.2f\n", i, c);

        c = up = 0.0;
    }

    return 0;
}
