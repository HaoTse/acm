#include <cstdio>
#include <algorithm>

using namespace std;

struct IN{
    int x;
    int y;
};

bool cmp(const IN a, const IN b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main(){
    int t, n;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        IN in[n], mid[n*(n-1)/2];
        int cur = 0, ans = 0;

        for(int i = 0; i < n; i++)
            scanf("%d %d", &in[i].x, &in[i].y);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mid[cur].x = in[i].x + in[j].x;
                mid[cur].y = in[i].y + in[j].y;
                cur++;
            }
        }

        sort(mid, mid + cur, cmp);

        int tmp = 1;
        for(int i = 1; i < cur; i++){
            if(mid[i].x == mid[i - 1].x && mid[i].y == mid[i - 1].y)
                tmp++;
            else{
                ans += tmp * (tmp - 1) / 2;
                tmp = 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
