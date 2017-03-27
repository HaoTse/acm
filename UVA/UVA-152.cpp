#include <cstdio>
#include <cmath>

#define MAXN 5003
#define INF 0x3f3f3f3f

struct POINT{
    int x, y, z;
}point[MAXN];

int dis(POINT a, POINT b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main(){
    int n;
    int ans[10] = {0};

    n = 0;
    while(scanf("%d %d %d", &point[n].x, &point[n].y, &point[n].z)){
        if(!point[n].x && !point[n].y && !point[n].z) break;
        n++;
    }
    for(int i = 0; i < n; i++){
        int Min = INF;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int d = dis(point[i], point[j]);
            Min = (Min < d) ? Min : d;
        }
        if(Min >= 0 && Min <= 9)
            ans[Min]++;
    }
    for(int i = 0; i < 10; i++){
        printf("%4d", ans[i]);
    }
    puts("");

    return 0;
}
