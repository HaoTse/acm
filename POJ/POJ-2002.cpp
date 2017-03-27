#include <cstdio>
#include <algorithm>

#define MAXN 1003

using namespace std;

struct POINT{
    int x, y;
}p[MAXN], tmp;

bool cmp(POINT a, POINT b){
    return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}

bool Binary_search(int low, int high){
    if(low > high) return false;
    int mid = (low + high) / 2;
    if(p[mid].x == tmp.x && p[mid].y == tmp.y)
        return true;
    if(cmp(p[mid], tmp))
        return Binary_search(mid + 1, high);
    return Binary_search(low, mid - 1);
}

int main(){
    int n;

    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        sort(p, p + n, cmp);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                tmp.x = p[i].x + p[i].y - p[j].y;
                tmp.y = p[i].y - p[i].x + p[j].x;
                if(!Binary_search(0, n - 1)) continue;
                tmp.x = p[j].x + p[i].y - p[j].y;
                tmp.y = p[j].y - p[i].x + p[j].x;
                if(!Binary_search(0, n - 1)) continue;
                ans++;
            }
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}
