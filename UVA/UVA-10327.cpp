#include <cstdio>
#include <cstdlib>

int main(){
    int num;
    int *in;
    int i, j;
    int result = 0;

    while(scanf("%d", &num) != EOF){
        in = (int *)malloc(sizeof(int) * num);
        for(i = 0; i < num; i++){
            scanf("%d", in + i);
        }

        for(i = 1; i < num; i++){
            int temp = *(in + i);
            for(j = i - 1; j >= 0; j--){
                if(temp < *(in + j)){
                    *(in + j + 1) = *(in + j);
                    result++;
                }
                else
                    break;
            }
            *(in + j + 1) = temp;
        }

        printf("Minimum exchange operations : %d\n", result);
        result = 0;
        free(in);
    }

    return 0;
}
