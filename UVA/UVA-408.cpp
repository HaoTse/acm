#include <cstdio>

int gcd(int a , int b){
    return (a == 0) ? b : gcd(b%a, a);
}

int main(){
    int step, M;

    while(scanf("%d %d", &step, &M) != EOF){

        printf("%10d%10d    ", step, M);
        (gcd(step, M) == 1) ? printf("Good Choice\n\n") : printf("Bad Choice\n\n");
    }

    return 0;
}
