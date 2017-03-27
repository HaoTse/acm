#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int num;
    long long ans = 0;

    scanf("%d", &num);
    int in[num];

    for(int i = 0; i < num; i++){
        scanf("%d", &in[i]);
    }

    sort(in, in + num);

    for(int i = 1; i < num; i++){
        ans += (long long)(in[i] - in[i - 1]) * i * (num - i) * 2;
    }

    printf("%lld\n", ans);

    return 0;
}
