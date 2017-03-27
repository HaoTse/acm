#include <cstdio>
#include <cmath>

int main(){
    int T, x1, y1, x2, y2, b, c, d;
    double x3, y3, x4, y4, a, a_left, h, unit_v_x, unit_v_y, n_unit_v_x, n_unit_v_y;
    bool f = false;

    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++){
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &b, &c, &d);

        a = hypot((x2 - x1), (y2 - y1));
        a_left = (d * d - b * b + (a - c) * (a - c)) / (2 * (a - c)); //d^2 - x^2 = b^2 - (a-c-x)^2
        h = sqrt(d * d - a_left * a_left);

        unit_v_x = (x2 - x1) * 1.0 / a;
        unit_v_y = (y2 - y1) * 1.0 / a;

        /* rotate vector
        x1 = x0 * cosB - y0 * sinB
        y1 = x0 * sinB + y0 * cosB
        */
        n_unit_v_x = unit_v_x * (a_left / d) - unit_v_y * (h / d);
        n_unit_v_y = unit_v_x * (h / d) + unit_v_y * (a_left / d);

        x4 = n_unit_v_x * d + x1;
        y4 = n_unit_v_y * d + y1;
        x3 = unit_v_x * c + x4;
        y3 = unit_v_y * c + y4;

        printf("Case %d:\n", Case);
        printf("%.8lf %.8lf %.8lf %.8lf\n", x3, y3, x4, y4);
    }
    return 0;
}
