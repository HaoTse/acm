#include <cstdio>

using namespace std;

int exGCD(int a, int b, int &X, int &Y){
    if(b == 0){
        X = 1;
        Y = 0;
        return a;
    }

    int gcd = exGCD(b, a % b, X, Y);
    int tmp = X;
    X = Y;
    Y = tmp - (a / b) * Y;
    return gcd;
}

int main(){
    int A, B;
    int X, Y;

    while(scanf("%d %d", &A, &B) != EOF){
        int gcd = exGCD(A, B, X, Y);
        printf("%d %d %d\n", X, Y, gcd);
    }

    return 0;
}
