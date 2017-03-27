#include <cstdio>
#include <cmath>

int main(){
    double n, p; //double range is +-10^308

    while(scanf("%lf %lf", &n, &p) != EOF){
        printf("%.0lf\n", pow(p, 1.0/n));
    }
    return 0;
}
