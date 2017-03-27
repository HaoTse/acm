#include <cstdio>

int v[4000] = {0}, w[4000] = {0}, c[13000] = {0};

void knapsack(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = m; j - w[i] >= 0; j--){
            c[j] = (c[j] > c[j - w[i]] + v[i]) ? c[j] : c[j - w[i]] + v[i];
        }
    }
}

int main(){
    int N, M;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    int ans = 0;

    knapsack(N, M);

    printf("%d\n", c[M]);

    return 0;
}
