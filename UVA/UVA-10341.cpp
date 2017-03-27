#include <cstdio>
#include <cmath>

int p, q, r, s, t, u;

double out(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x);
}

int main(){

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
        double left = 0.0, right = 1.0, mid, eps = 1e-8;
        bool f = 1;

        while((right - left) > eps){
            mid = (left + right) / 2;

            if(out(mid) < (-1 * u)){
                right = mid;
                f = 1;
            }
            else{
                left = mid;
                f = 0;
            }
        }

        mid = (f) ? right : left;
        if(((out(right)+u) * (out(left)+u)) > 0)
            printf("No solution\n");
        else
            printf("%.4lf\n", mid);

    }
    return 0;
}
