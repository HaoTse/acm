#include <cstdio>

#define MAXN 77

using namespace std;

int main(){
    int n;
    int dp[MAXN];

    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 2;
    for(int i = 4; i < MAXN; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    while(scanf("%d", &n) != EOF){
        printf("%d\n", dp[n]);
    }

    return 0;
}