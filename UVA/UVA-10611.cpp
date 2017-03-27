#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N, Q, tmp;
    int in[50003] = {0};

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &in[i]);
    }
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &tmp);
        int low, high;
        low = lower_bound(in, in + N, tmp) - in - 1;
        high = upper_bound(in, in + N, tmp) - in - 1;

        low = (in[low] == tmp) ? low - 1 : low;
        high = (in[high] <= tmp) ? high + 1 : high;

        (low < 0) ? printf("X ") : printf("%d ", in[low]);
        (high >= N) ? printf("X\n") : printf("%d\n", in[high]);
    }

    return 0;
}
