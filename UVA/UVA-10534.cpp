#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int in[10003] = {0}, ans_lis[10003] = {0}, ans_lds[10003] = {0};
    vector<int> lis, lds;

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &in[i]);
        }

        ans_lis[0] = 0, ans_lds[n - 1] = 0;
        lis.clear(), lds.clear();
        lis.push_back(in[0]);
        lds.push_back(in[n - 1]);
        for(int i = 0, j = n - 1; i < n; i++, j--){
            int t = lower_bound(lis.begin(), lis.end(), in[i]) - lis.begin();

            if(t == lis.size()) lis.push_back(in[i]);
            else lis[t] = in[i];

            int s = lower_bound(lds.begin(), lds.end(), in[j]) - lds.begin();

            if(s == lds.size()) lds.push_back(in[j]);
            else lds[s] = in[j];

            ans_lis[i] = lis.size(), ans_lds[n - i - 1] = lds.size();
        }

        int Max = 0;
        for(int i = 0; i < n; i++){
            int Min = (ans_lis[i] > ans_lds[i]) ? ans_lds[i] : ans_lis[i];
            Max = (Max > Min) ? Max : Min;
        }
        Max -= 1;
        printf("%d\n", 2 * Max + 1);
    }
    return 0;
}
