#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, Case = 1;
    vector<int> in;
    vector<int> tmp;

    while(1){
        in.clear();
        tmp.clear();

        scanf("%d", &n);
        if(n == -1) break;
        in.push_back(n);

        while(scanf("%d", &n) && n != -1){
            in.push_back(n);
        }

        tmp.push_back(in.back());
        for(int i = in.size() - 2; i >= 0; i--){
            int t = lower_bound(tmp.begin(), tmp.end(), in[i]) - tmp.begin();
            if(t == tmp.size()) tmp.push_back(in[i]);
            else tmp[t] = in[i];
        }

        if(Case != 1) printf("\n");
        printf("Test #%d:\n", Case++);
        printf("  maximum possible interceptions: %d\n", tmp.size());
    }
    return 0;
}
