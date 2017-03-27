#include <cstdio>

int main(){
    long long M, N;
    long long ans = 0;

    while(scanf("%lld %lld", &M, &N)){
        if(M == 0 && N == 0)
            break;
        ans = ((M - 1) + (N - 1)) * M * N;
        ans += (N > M) ? (2 * (N - M + 1) * M * (M - 1)) : (2 * (M - N + 1) * N * (N - 1)); //longest diagonal, include left and right
        ans += (N > M) ? (2 * 2 * M * (M - 1) * (M - 2) / 3) : (2 * 2 * N * (N - 1) * (N - 2) / 3); //C(2, 2) + C(3, 2) + ... + C(a - 1, 2) = C(a, 3)
        printf("%lld\n", ans);

    }

    return 0;
}
