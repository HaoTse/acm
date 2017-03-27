#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX 16

int n;
int ans[MAX + 1] = {0};
bool visited[MAX + 1] = {false};
bool isPrime[MAX + MAX];

void sieve(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < sqrt(MAX + MAX); i++){
        if(isPrime[i]){
            for(int j = i + i; j < MAX + MAX; j += i)
                isPrime[j] = false;
        }
    }
}

void backtracking(int pos, int len){
    if(len == n && isPrime[ans[0] + ans[len - 1]]){
        for(int i = 0; i < n; i++){
            if(i) printf(" %d", ans[i]);
            else printf("%d", ans[i]);
        }
        printf("\n");
    }
    for(int i = 2; i <= n; i++){
        if(!visited[i] && isPrime[ans[len - 1] + i]){
            visited[i] = true;

            ans[len] = i;
            backtracking(i, len + 1);

            visited[i] = false;
        }
    }
}

int main(){
    int Case = 0;

    sieve();
    ans[0] = 1;
    visited[1] = true;
    while(scanf("%d", &n) != EOF){
        if(Case++) printf("\n");
        printf("Case %d:\n", Case);
        backtracking(1, 1);
    }
    return 0;
}
