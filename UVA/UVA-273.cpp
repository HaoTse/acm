#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 13

using namespace std;

struct POINT{
    int x, y;
    POINT(int x = 0, int y = 0): x(x), y(y){}
};

POINT operator - (POINT a, POINT b){
    return POINT(a.x - b.x, a.y - b.y);
}

struct LINE{
    POINT a, b;
};

int Cross(POINT a, POINT b){
    return a.x * b.y - a.y * b.x;
}

bool in_interval(POINT a, POINT b, POINT c){
    POINT Min, Max;
    if(a.x > b.x) Min.x = b.x, Max.x = a.x;
    else Min.x = a.x, Max.x = b.x;
    if(a.y > b.y) Min.y = b.y, Max.y = a.y;
    else Min.y = a.y, Max.y = b.y;
    if(Min.x <= c.x && c.x <= Max.x && Min.y <= c.y && c.y <= Max.y) return true;
    return false;
}

bool segments_intersect(POINT a, POINT b, POINT c, POINT d){
    int d1 = Cross(a - c, d - c);
    int d2 = Cross(b - c, d - c);
    int d3 = Cross(c - a, b - a);
    int d4 = Cross(d - a, b - a);
    if(d1 * d2 < 0 && d3 * d4 < 0) return true;
    if(!d1 && in_interval(c, d, a)) return true;
    if(!d2 && in_interval(c, d, b)) return true;
    if(!d3 && in_interval(a, b, c)) return true;
    if(!d4 && in_interval(a, b, d)) return true;
    return false;
}

int main(){
    int Case, n;
    bool connect[MAXN][MAXN];
    LINE line[MAXN];

    scanf("%d", &Case);
    while(Case--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d %d", &line[i].a.x, &line[i].a.y, &line[i].b.x, &line[i].b.y);
        }

        memset(connect, false, sizeof(connect));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) connect[i][i] = true;
                else if(segments_intersect(line[i].a, line[i].b, line[j].a, line[j].b))
                    connect[i][j] = connect[j][i] = true;
            }
        }
        //Use Floyd
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(i != j && connect[i][k] && connect[k][j])
                        connect[i][j] = true;

        int a, b;
        while(scanf("%d %d", &a, &b)){
            if(!a && !b) break;
            (connect[a][b]) ? puts("CONNECTED") : puts("NOT CONNECTED");
        }

        if(Case) puts("");
    }

    return 0;
}