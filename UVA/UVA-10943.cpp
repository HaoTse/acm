#include <cstdio>

int main(){
    int ans[201][201] = {0};
    int N, K;

    ans[0][0] = 1;
    for(int i = 1; i < 201; i++){
        ans[i][0] = 1;
        for(int j = 1; j < 201; j++){
            ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % 1000000;//C(i - 1, j) + C(i - 1, j - 1) = C(i, j)
        }
    }

    while(scanf("%d %d", &N, &K) != EOF){
        if(N == 0 & K == 0)
            break;

        //x + y + z = N (x, y, z >= 0) : H(3, 10)
        //H(i , j) = H(i + j - 1, j);
        printf("%d\n", ans[N + K - 1][N]);
    }
    return 0;
}
