#include <cstdio>
#include <algorithm>

using namespace std;

int in[501 * 501];

int main(){
    int N, M, Q;

    while(scanf("%d %d", &N, &M)){
        if(N == 0 && M == 0)
            break;

        for(int i = 0; i < N * M; i++){
                scanf("%d", &in[i]);

        }

        int a, b, low, high, ans = 0, out = 0;
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &a, &b);
            out = 0;
            for(int i = 0; i < N; i++){

                if(a > in[N * M - 1])
                    break;

                low = lower_bound(in + i * M, in + M * (i + 1) - 1, a) - in;

                if(in[low] < a)
                    continue;

                if(b < in[low])
                    continue;

                else{
                    int tmp = low % M;
                    ans = 0;
                    for(int j = i; j < N; j++){
                        if(in[j * M + tmp] > b){
                            tmp = tmp - 1;
                            break;
                        }
                        tmp++;
                        if(tmp >= M || j + 1 >= N){
                            tmp = tmp - 1;
                            break;
                        }
                    }
                    ans = tmp - low % M + 1;
                    out = (out > ans) ? out : ans;
                }

                //printf("%d=%d %d=%d\n", low, in[low], high, in[high]);
            }
            printf("%d\n", out);
        }
        printf("-\n");
    }
    return 0;
}
