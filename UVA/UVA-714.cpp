#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int in[503];

int main(){
    int N, m, k, large;
    long long sum = 0, tmp;
    stack<int> loc;

    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &m, &k);
        memset(in, 0, sizeof(in));

        sum = 0, large = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &in[i]);
            sum += in[i];
            large = (large > in[i]) ? large : in[i];
        }

        long long left = large, right = sum, mid;

        while(left < right){
            int cnt = 1;
            tmp = 0;
            mid = (left + right) / 2;
            for(int i = 0; i < m; i++){
                if(in[i] + tmp > mid){
                    cnt++;
                    tmp = 0;
                }
                tmp += in[i];
            }
            if(cnt > k)
                left = mid + 1;
            else
                right = mid;
        }
        long long num = left;

        tmp = 0;
        for(int i = m - 1; i >= 0; i--){
            if(tmp + in[i] > num || k - 1 > i){
                loc.push(i);
                tmp = in[i];
                k--;
            }
            else
                tmp += in[i];
        }

        for(int i = 0; i < m; i++){
            if(i)
                printf(" ");
            printf("%d", in[i]);

            if(loc.size() && i == loc.top()){
                printf(" /");
                loc.pop();
            }
        }
        printf("\n");
    }

    return 0;
}
