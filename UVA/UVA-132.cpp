#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

#define MAXN 100
#define INF 0x3f3f3f3f

using namespace std;

struct POINT{
    int x, y;
    POINT(int x = 0, int y = 0): x(x), y(y){}
} p[MAXN], p_[MAXN], ch[MAXN + 1];

POINT operator - (POINT a, POINT b){
    return POINT(a.x - b.x, a.y - b.y);
}

int Cross(POINT &o, POINT &a, POINT &b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int Dot(POINT a, POINT b){
    return a.x * b.x + a.y * b.y;
}

bool cmp(POINT &a, POINT &b){
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int Andrew_monotone_chain(int n){
    sort(p, p + n, cmp);

    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && Cross(ch[m - 2], ch[m - 1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }

    for(int i = n - 1, t =  m + 1; i >= 0; i--){
        while(m >= t && Cross(ch[m - 2], ch[m - 1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }

    m--;
    return m;
}

// Use dot to determine
bool in_interval(POINT a, POINT b, POINT c){
    return Dot(c - a, b - a) >= 0 && Dot(c - b, a - b) >= 0;
}

bool segments_intersect(POINT a, POINT b, POINT c){
    int d = Cross(a, b, c);
    if(!d && in_interval(a, b, c)) return true;
    return false;
}

int main(){
    string id;

    while(getline(cin, id) && id != "#"){
        if(id == "") continue;
        int x, y, n = 0;
        POINT centre;

        scanf("%d %d", &centre.x, &centre.y);
        while(scanf("%d %d", &x, &y)){
            if(!x && !y) break;
            p[n] = p_[n] = POINT(x, y);
            n++;
        }

        int m = Andrew_monotone_chain(n);
        int ans = INF;
        for(int i = 0, j = 1; i < m; i++, j++){
            j = j % n;
            if(in_interval(ch[i], ch[j], centre)){
                int tmp = 0;
                // find label (the maximum)
                for(int k = 0; k < n; k++){
                    if(segments_intersect(ch[i], ch[j], p_[k]))
                        tmp = max(tmp, k);
                }
                ans = min(ans, tmp);
            }
        }
        printf("%-20s%d\n", id.c_str(), ans + 1);
    }

    return 0;
}