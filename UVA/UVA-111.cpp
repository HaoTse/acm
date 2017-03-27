#include <cstdio>

int main(){
    int n;
    int arr[25];
    int right[25];
    int in[25];
    int tmp[25][25] = {0};
    bool f = true;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        right[arr[i]] = i;
    }

    while(f){
        for(int i = 1; i <= n; i++){
            if(scanf("%d", &arr[i]) == EOF){
                f = false;
                break;
            }
            in[arr[i]] = i;
        }
        if(!f) break;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){

                if(right[i] == in[j]){
                    tmp[i][j] = tmp[i - 1][j - 1] + 1;
                }
                else{
                    tmp[i][j] = (tmp[i - 1][j] > tmp[i][j - 1]) ? tmp[i - 1][j] : tmp[i][j - 1];
                }
            }
        }
        printf("%d\n", tmp[n][n]);
    }

    return 0;
}
