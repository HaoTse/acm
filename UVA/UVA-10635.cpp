#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t, n, p, q;
    int seq[62501] = {0}; //250 * 250  + 1 = 62501
    vector<int> lcs;

    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        scanf("%d %d %d", &n, &p, &q);

        lcs.clear();
        memset(seq, 0, sizeof(seq));
        for(int i = 1; i <= p + 1; i++){
            int tmp;
            scanf("%d", &tmp);
            seq[tmp] = i;
        }
        for(int i = 1; i <= q + 1; i++){
            int tmp;
            scanf("%d", &tmp);

            if(!seq[tmp]) continue;
            int t = lower_bound(lcs.begin(), lcs.end(), seq[tmp]) - lcs.begin();
            if(t == lcs.size())
                lcs.push_back(seq[tmp]);
            else
                lcs[t] = seq[tmp];
        }

        printf("Case %d: %d\n", Case, lcs.size());
    }
    return 0;
}
