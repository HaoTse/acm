#include <cstdio>

int main(){
    float num;
    float sum = 0.0;

    for(int i = 0; i < 12; i++){
        scanf("%f", &num);
        sum += num;
    }

    printf("$%.2f", sum / 12.0);

    return 0;
}
