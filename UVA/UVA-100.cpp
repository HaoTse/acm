#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int alg(long a){
    long cnt= 1;

    while(a != 1){
        if(a % 2 == 0)
            a = a/2;
        else
            a = a*3 + 1;

        cnt++;
    }

    return cnt;
}

int main(){

    long a, b, l, s, tmp, result;


    while(scanf("%ld %ld", &a, &b) != EOF){
        l = (a > b) ? a : b;
        s = (a > b) ? b : a;

        result = 0;

        for(tmp = s; tmp <= l; tmp++){
            if(alg(tmp) > result)
                result = alg(tmp);
        }
        printf("%ld %ld %ld\n", a, b, result);
    }

    return 0;
}
