#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAXN 100

using namespace std;

struct POINT{
    int x, y;
} point[MAXN], ch[MAXN + 1];

int Cross(POINT &o, POINT &a, POINT &b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(POINT &a, POINT &b){
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int Andrew_monotone_chain(int n){
    sort(point, point + n, cmp);

    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && Cross(ch[m - 2], ch[m - 1], point[i]) <= 0)
            m--;
        ch[m++] = point[i];
    }

    for(int i = n - 1, t =  m + 1; i >= 0; i--){
        while(m >= t && Cross(ch[m - 2], ch[m - 1], point[i]) <= 0)
            m--;
        ch[m++] = point[i];
    }

    m--;
    return m;
}

double ploygon_area(int n, POINT p[]){
    double area = 0.0;
    for(int i = 1; i < n - 1; i++)
        area += Cross(p[0], p[i], p[i + 1]);

    return fabs(area) / 2.0;
}

int main(){
    int n, x, y, index = 0;
    double space, tile;

    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &point[i].x, &point[i].y);
        }

        space = ploygon_area(n, point);
        int m = Andrew_monotone_chain(n);
        tile = ploygon_area(m, ch);
        double ans = (tile - space) / tile * 100;

        printf("Tile #%d\n", ++index);
        printf("Wasted Space = %.2lf %%\n\n", ans);
    }

    return 0;
}