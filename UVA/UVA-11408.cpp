#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 5000001

using namespace std;

int main(){
    int sieve[MAX]; //1 is visited
    int sum[MAX];
    int dePrime[MAX];
    vector<int> prime;

    memset(sieve, 0, sizeof(sieve));
    memset(sum, 0, sizeof(sum));
    memset(dePrime, 0, sizeof(dePrime));

    //create table
    for(int i = 2; i < MAX; i++){
        if(!sieve[i]){
            prime.push_back(i);
            sum[i] = i;
        }
        for(int j = 0; j < prime.size() && i * prime[j] < MAX; j++){
            sieve[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                sum[i * prime[j]] = sum[i];
                break;
            }
            sum[i * prime[j]] = sum[i] + prime[j];
        }
        dePrime[i] = dePrime[i - 1] + !sieve[sum[i]];
    }

    int a, b;
    while(scanf("%d", &a) && a){
        scanf("%d", &b);
        printf("%d\n", dePrime[b] - dePrime[a - 1]);
    }

    return 0;
}
