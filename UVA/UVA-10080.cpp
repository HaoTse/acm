#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int llink[103], rlink[103];
bool used[103];
vector<int> List[103];

struct POINT{
    double x, y;
};
POINT gopher[103], hole[103];

bool DFS(int now){
    int i, next;
    for(int i = 0; i < List[now].size(); i++){
        next =List[now][i];
        if(!used[next]){
            used[next] = true;
            if(!rlink[next] || DFS(rlink[next])){
                rlink[next] = now;
                llink[now] = next;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int L){
    int ret = 0;
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
    for(int i = 1; i <= L; i++){
        memset(used, false, sizeof(used));
        if(DFS(i))
            ret++;
    }
    return ret;
}

int main(){
    int n, m, s, v;

    while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF){
        for(int i = 0; i <= n; i++)
            List[i].clear();

        for(int i = 1; i <= n; i++)
            scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
        for(int i = 1; i <= m; i++)
            scanf("%lf %lf", &hole[i].x, &hole[i].y);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                double dis = sqrt(pow(gopher[i].x - hole[j].x, 2) + pow(gopher[i].y - hole[j].y, 2));
                if(dis / v <= s) List[i].push_back(j);
            }
        }

        printf("%d\n", n - bipartite(n));
    }

    return 0;
}
