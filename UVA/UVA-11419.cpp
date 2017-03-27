#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int llink[1003], rlink[1003];
bool usedx[1003], usedy[1003];
vector<int> List[1003];

bool DFS(int now){
    int next;
    usedx[now] = true;
    for(int i = 0; i < List[now].size(); i++){
        next = List[now][i];
        if(!usedy[next]){
            usedy[next] = true;
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
        memset(usedy, false, sizeof(usedy));
        if(DFS(i))
            ret++;
    }
    return ret;
}

int main(){
    int r, c, n;

    while(scanf("%d %d %d", &r, &c, &n)){
        if(!r && !c && !n) break;

        for(int i = 0; i <= r; i++)
            List[i].clear();

        int x, y;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            List[x].push_back(y);
        }

        printf("%d", bipartite(r));
        //König theory
        memset(usedx, false, sizeof(usedx));
        memset(usedy, false, sizeof(usedy));
        for(int i = 1; i <= r; i++)
            if(llink[i] == 0)
                DFS(i);
        for(int i = 1; i <= r; i++)
            if(!usedx[i]) printf(" r%d", i);
        for(int i = 1; i <= c; i++)
            if(usedy[i]) printf(" c%d", i);
        puts("");
    }

    return 0;
}


