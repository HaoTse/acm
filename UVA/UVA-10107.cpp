#include <cstdio>
#define N 10000

int main(){
    int in;
    int cnt = 0;
    int tmp[N] = {-1};
    int i, j;

    while(scanf("%d", &in) != EOF){

        for(i = 0; i < cnt; i++){
            if(tmp[i] > in){
                for(j = cnt; j >= i; j--)
                    tmp[j] = tmp[j - 1];
                break;
            }
        }
        tmp[i] = in;
        cnt++;

        if(cnt % 2)
            printf("%d\n", tmp[cnt / 2]);
        else
            printf("%d\n", (tmp[(cnt / 2) - 1] + tmp[cnt / 2]) / 2);
    }

    return 0;
}
