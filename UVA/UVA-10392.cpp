#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define MAX 1000000

using namespace std;

vector<int> prime;

bool isPrime(int n){
    for(int i = 0; prime[i] * prime[i] <= n; i++)
        if(n % prime[i] == 0)
            return false;
    return true;
}

void MakePrime(){
    prime.push_back(2);
    prime.push_back(3);
    for(int i = 5, gap = 2; i < MAX; i += gap, gap = 6 - gap)
        if(isPrime(i))
            prime.push_back(i);
}

int main(){
    long long int num;
    MakePrime();

    while(scanf("%lld", &num)){
        if(num < 0)
            break;

        for(int i = 0; i < prime.size(); i++){
            while(num%prime[i] == 0){
                printf("    %d\n", prime[i]);
                num = num / prime[i];
            }
            if(num == 1)
                break;
        }
        if(num > 1000000)
            printf("    %lld\n", num);

        printf("\n");
    }

    return 0;
}
