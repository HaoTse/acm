#include <cstdio>
#include <cmath>

int main(){
    double l, n, C, eps = 1e-8;

    while(scanf("%lf %lf %lf", &l, &n, &C)){
        if(l < 0 && n < 0 && C < 0)
            break;

        /*
        r * theta/2 = L'/2 _ (1)
        theta/2 = arcsin(L/2 / r) _ (2)
        r^2 - (r-x)^2 = (L/2)^2 _ (3)

        (1) & (2) -> r * arcsin(L/2 / r) = L'/2
        (3) -> (2*r - x) * x = (L/2)^2 -> 2*r*x - x^2 = (L/2)^2 -> r = ((L/2)^2 + x^2) / x*2
        */
        double newL = (1 + n * C) * l;
        double left = 0, right = l / 2;

        while(right - left > eps){
            double mid = (right + left) / 2;
            double r = (l * l / 4 + mid * mid) / (2 * mid);

            if(r * asin((l / 2) / r) < newL / 2)
                left = mid;
            else
                right = mid;
        }

        printf("%.3f\n", left);
    }

    return 0;
}
