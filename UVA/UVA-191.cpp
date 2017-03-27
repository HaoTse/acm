#include <cstdio>
#include <cmath>

#define EPS 1e-8

struct POINT{
    double x, y;
    POINT(double x = 0, double y = 0): x(x), y(y){}
};

POINT operator - (POINT a, POINT b){
    return POINT(a.x - b.x, a.y - b.y);
}

int dcmp(double x){
    if(fabs(x) <= EPS) return 0;
    else return (x < 0) ? -1 : 1;
}

double Cross(POINT a, POINT b){
    return a.x * b.y - a.y * b.x;
}

int in_interval(POINT a, POINT b, POINT c){
    POINT Min, Max;
    if(a.x > b.x) Min.x = b.x, Max.x = a.x;
    else Min.x = a.x, Max.x = b.x;
    if(a.y > b.y) Min.y = b.y, Max.y = a.y;
    else Min.y = a.y, Max.y = b.y;
    if(Min.x <= c.x && c.x <= Max.x && Min.y <= c.y && c.y <= Max.y) return 1;
    return 0;
}

int segments_intersect(POINT a, POINT b, POINT c, POINT d){
    double d1 = Cross(a - c, d - c);
    double d2 = Cross(b - c, d - c);
    double d3 = Cross(c - a, b - a);
    double d4 = Cross(d - a, b - a);
    if(dcmp(d1 * d2) < 0 && dcmp(d3 * d4) < 0) return 1;
    if(!dcmp(d1) && in_interval(c, d, a) == 1) return 1;
    if(!dcmp(d2) && in_interval(c, d, b) == 1) return 1;
    if(!dcmp(d3) && in_interval(a, b, c) == 1) return 1;
    if(!dcmp(d4) && in_interval(a, b, d) == 1) return 1;
    return 0;
}

int main(){
    int Case;
    double xleft, ytop, xright, ybottom;
    POINT S, E, rect1, rect2, rect3, rect4;
    //FILE *fPtr = freopen("output.txt", "w", stdout);

    scanf("%d", &Case);
    while(Case--){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &S.x, &S.y, &E.x, &E.y, &xleft, &ytop, &xright, &ybottom);
        rect1.x = rect2.x = xleft;
        rect1.y = rect4.y = ytop;
        rect3.x = rect4.x = xright;
        rect3.y = rect2.y = ybottom;

        if(segments_intersect(S, E, rect1, rect2)){
            puts("T");
            continue;
        }
        if(segments_intersect(S, E, rect1, rect4)){
            puts("T");
            continue;
        }
        if(segments_intersect(S, E, rect3, rect2)){
            puts("T");
            continue;
        }
        if(segments_intersect(S, E, rect3, rect4)){
            puts("T");
            continue;
        }
        if(in_interval(rect1, rect3, S) && in_interval(rect1, rect3, E)){
            puts("T");
            continue;
        }
        puts("F");
    }

    return 0;
}
