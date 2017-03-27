#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    vector<long long> v;
    long long a;

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            long long tmp = pow(2, i) * pow(3, j);
            if(tmp - 1 > LONG_MAX)
                break;
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());
    while(scanf("%lld", &a)){
        if(a == 0)
            break;
        long long tmp = upper_bound(v.begin(), v.end(), a) - v.begin();
        tmp = (v[tmp - 1] == a) ? tmp - 1 : tmp;

        printf("%lld\n", v[tmp]);
    }
    return 0;
}
