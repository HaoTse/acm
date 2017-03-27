#include <cstdio>

int main(){
    long long int a, b, i, tmp;
    double eps;

    while(scanf("%lld %lld", &a, &b) != EOF){
        scanf("%lf", &eps);
        for(i = 1; ; i++){
            tmp = 1;
            while((i * a + tmp) % b != 0)
                tmp++;
            if((double)((tmp * 1.0) / (double)(b * i)) <= eps)
                break;
        }
        printf("%lld %lld\n", ((i * a + tmp) / b), i);
    }
    return 0;
}
