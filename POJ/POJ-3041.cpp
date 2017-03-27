#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int llink[503], rlink[503];
bool used[503];
vector<int> List[503];

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
    int n, k;

    while(scanf("%d %d", &n, &k) != EOF){
        for(int i = 0; i <= n; i++)
            List[i].clear();

        int x, y;
        for(int i = 0; i < k; i++){
            scanf("%d %d", &x, &y);
            List[x].push_back(y);
        }

        printf("%d\n", bipartite(n));
    }

    return 0;
}

