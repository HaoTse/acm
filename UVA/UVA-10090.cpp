#include <cstdio>
#include <cmath>

#define ll long long

using namespace std;

ll exGCD(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = exGCD(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - (a/b) * y;
    return gcd;
}

int main(){
    ll n, c1, c2, t1, t2, x0, y0, x, y, gcd;

    while(scanf("%lld", &n)){
        if(n == 0)
            break;
        scanf("%lld %lld %lld %lld", &c1, &t1, &c2, &t2);

        gcd = exGCD(t1, t2, x0, y0);

        /*
        after /gcd(a, b) get aX + bY = n
        X = n * x + b * t
        Y = n * y - a * t

        -> c1 * (xi * n + yi * t) + c2 * (yi * n - xi * t) = n
        */
        if(n % gcd == 0){
            if(c1 * 1.0 / t1 < c2 * 1.0 / t2){
                ll t = floor(1.0 * y0 * n / t1);
                x = x0 * n / gcd + t2 / gcd * t;
                y = y0 * n / gcd - t1 / gcd * t;
            }
            else{
                ll t = floor(1.0 * x0 * n / t2);
                x = x0 * n / gcd - t2 / gcd * t;
                y = y0 * n / gcd + t1 / gcd * t;
            }
            if(x >= 0 && y >= 0)
                printf("%lld %lld\n", x, y);
            else
                printf("failed\n");
        }
        else
            printf("failed\n");
    }

    return 0;
}
