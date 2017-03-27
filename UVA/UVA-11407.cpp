#include <cstdio>

#define MAX 10001

int main(){
    int t, N;
    int DP[MAX];

    for(int i = 0; i < MAX; i++)
        DP[i] = MAX;
    DP[0] = 0;
    for(int i = 1; i * i < MAX; i++){
        for(int j = i * i; j < MAX; j++){
            DP[j] = (DP[j] < DP[j - i * i] + 1) ? DP[j] : DP[j - i * i] + 1;
        }
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        printf("%d\n", DP[N]);
    }

    return 0;
}

