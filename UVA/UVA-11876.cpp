#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 1000003

using namespace std;

int main(){
    int nod[MAX] = {0};
    vector<int> N;

    for(int i = 1; i < MAX; i++){
        for(int j = 1; j * i < MAX; j++){
            nod[j * i]++;
        }
    }

    N.push_back(1);
    for(int i = 1;; i++){
        int tmp = N[i - 1];
        if(tmp + nod[tmp] > MAX)
            break;
        N.push_back(tmp + nod[tmp]);
    }

    int T, a, b;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d %d", &a, &b);
        int low = lower_bound(N.begin(), N.end(), a) - N.begin();
        int high = upper_bound(N.begin(), N.end(), b) - N.begin();

        printf("Case %d: %d\n", i, high - low);
    }

    return 0;
}
