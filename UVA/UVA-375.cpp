#include <cstdio>
#include <cmath>

#define _USE_MATH_DEFINES

int main(){
    int c;
    double B, H, eps = 0.000001;

    scanf("%d", &c);
    while(c--){
        scanf("%lf %lf", &B, &H);
        double T, R, ans = 0;
        while(1){
            T = sqrt(B * B / 4 + H * H);
            R = B * H / (2 * T + B);
            if(R < eps)
                break;
            ans += 2 * R;
            B = B * ((H - 2 * R) / H);
            H = H - 2 *R;
        }
        printf("%13lf\n", (ans * M_PI));
        if(c)
            printf("\n");
    }
    return 0;
}
