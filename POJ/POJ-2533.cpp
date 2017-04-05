#include <cstdio>

using namespace std;

int main(){
    int N;
    int data[1001];
    int LIS[1001];
    int ans = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &data[i]);

        LIS[i] = 1;
        for(int j = 0; j < i; j++){
            if(data[j] < data[i] && LIS[j] + 1 > LIS[i])
                LIS[i] = LIS[j] + 1;
        }

        ans = (ans > LIS[i]) ? ans : LIS[i];
    }
    printf("%d\n", ans);

    return 0;
}
