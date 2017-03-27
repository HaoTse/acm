#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX 100000005

using namespace std;

bool isprime[MAX];

void MakePrime(){
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++){
        if(isprime[i])
            for(int j = i * i; j < MAX; j += i)
                isprime[j] = false;
    }
}

int main(){
    MakePrime();
    int a;

    while(scanf("%d", &a) != EOF){
        int i;
        if(a % 2 == 1){
            if(isprime[a - 2])
                printf("%d is the sum of 2 and %d.\n", a, a - 2);
            else
                printf("%d is not the sum of two primes!\n", a);
            continue;
        }
        for(i = a / 2; i < a; i++){
            if(i == a - i)
                continue;
            if(isprime[i] && isprime[a - i]){
                printf("%d is the sum of %d and %d.\n", a, a - i, i);
                break;
            }
        }
        if(i == a)
            printf("%d is not the sum of two primes!\n", a);
    }

    return 0;
}
