#include <cstdio>

int main(){
    int n, m, left = 0;
    int in[1003];
    long long right = 0;

    while(scanf("%d %d", &n, &m) != EOF){
        left = 0, right = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &in[i]);
            left = (left > in[i]) ? left : in[i];
            right += in[i];
        }

        long long mid = 0, sum = 0;
        int cnt = 1;
        while(left < right){
            sum = 0, cnt = 1;
            mid = (left + right) / 2;
            for(int i = 0; i < n; i++){
                if(sum + in[i] > mid){
                    cnt++;
                    sum = 0;
                }
                sum += in[i];
            }
            if(cnt > m)
                left = mid + 1;
            else
                right = mid;
        }

        printf("%lld\n", right);
    }

    return 0;
}
