#include <cstdio>

int v[5] = {1, 5, 10, 25, 50};

int main(){
    int n;
    int dp[7490] = {0};

    dp[0] = 1;
    for(int j = 0; j < 5; j++){
        for(int i = 1; i < 7490; i++) {
            if(i - v[j] < 0)
                continue;
            if(dp[i - v[j]] != 0){
                dp[i] += dp[i - v[j]];
            }
        }
    }

    while(scanf("%d", &n) != EOF){
        printf("%d\n", dp[n]);
    }
    return 0;
}
