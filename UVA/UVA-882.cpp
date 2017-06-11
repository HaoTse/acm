#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXK 13
#define MAXM 103
#define INF 0x3f3f3f3f

using namespace std;

int dp[MAXK][MAXM][MAXM];

int dfs(int k, int low, int high){
    if(dp[k][low][high] != -1)
        return dp[k][low][high];

    if(low == high) return dp[k][low][high] = 0;
    if(!k) return dp[k][low][high] = INF;

    dp[k][low][high] = INF;
    for(int i = low + 1; i <= high; i++)
        dp[k][low][high] = min(dp[k][low][high], i + max(dfs(k - 1, low, i - 1), dfs(k, i, high)));
    
    return dp[k][low][high];
}

int main(){
    int n, k, m;
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &k, &m);
        printf("%d\n", dfs(k, 0, m));
    }

    return 0;
}