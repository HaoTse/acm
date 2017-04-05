#include <cstdio>

using namespace std;

int main(){
    int n;
    int lLIS[1001], rLIS[1001];
    double data[1001];
    int Max = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &data[i]);

    for(int i = 0; i < n; i++){
        lLIS[i] = 1;
        for(int j = 0; j < i; j++){
            if(data[j] < data[i] && lLIS[j] + 1 > lLIS[i])
                lLIS[i] = lLIS[j] + 1;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        rLIS[i] = 1;
        for(int j = n - 1; j > i; j--){
            if(data[j] < data[i] && rLIS[j] + 1 > rLIS[i])
                rLIS[i] = rLIS[j] + 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            Max = (Max > lLIS[i] + rLIS[j]) ? Max : lLIS[i] + rLIS[j];
    }
    printf("%d\n", n - Max);

    return 0;
}
