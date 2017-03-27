#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 103

using namespace std;

int llink[MAXN], rlink[MAXN];
bool used[MAXN];
vector<int> List[MAXN];

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
    int n, m, k;

    while(scanf("%d", &n) && n){
        scanf("%d %d", &m, &k);

        for(int i = 0; i <= n; i++)
            List[i].clear();

        int i, x, y;
        for(int j = 0; j < k; j++){
            scanf("%d %d %d", &i, &x, &y);
            if(!y) continue;
            List[x].push_back(y);
        }

        printf("%d\n", bipartite(n));
    }

    return 0;
}


