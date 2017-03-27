#include <cstdio>

int main(){
    int N;
    int in[10001], mss[10001];
    int ans = 0;

    while(scanf("%d", &N) && N != 0){
        ans = 0;
        for(int i = 0; i < N; i++)
            scanf("%d", &in[i]);

        mss[0] = in[0];
        for(int i = 1; i < N; i++){
            if(mss[i - 1] <= 0)
                mss[i] = in[i];
            else
                mss[i] = mss[i - 1] + in[i];
            ans = (mss[i] > ans) ? mss[i] : ans;
        }
        if(ans > 0)
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
