#include <cstdio>
#include <cstring>

#define MAXN 1000
#define DIGIT 3000

using namespace std;
int num[DIGIT], ans[MAXN];

int multiply(int n, int s){
    int carry = 0;

    for(int i = 0; i < s; i++){
        int prod = num[i] * n + carry;
        num[i] = prod % 10;
        carry = prod / 10;
    }

    while(carry){
        num[s] = carry % 10;
        carry = carry / 10;
        s++;
    }

    return s;
}

int main(){
    int n, n_size = 1;
    memset(ans, 0, sizeof(ans));
    num[0] = ans[0] = 1;

    for(int i = 1; i <= MAXN; i++){
        n_size = multiply(i, n_size);
        for(int j = 0; j < n_size; j++)
            ans[i] += num[j];
    }

    while(scanf("%d", &n) != EOF){
        printf("%d\n", ans[n]);
    }

    return 0;
}