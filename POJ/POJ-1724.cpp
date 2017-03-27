#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int dis[103][10003];
bool inQueue[103];
int K, N, R;

struct NODE{
    vector<int> d, l, t;
}node[103];

void SPFA(){
    queue<int> q;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dis[i][j] = INF;
        }
        inQueue[i] = false;
    }
    for(int j = 0; j <= K; j++)
        dis[1][j] = 0;
    inQueue[1] = true;
    q.push(1);

    while(!q.empty()){
        int tmp = q.front();
        inQueue[tmp] = false;
        q.pop();

        for(int i = 0; i < node[tmp].d.size(); i++){
            for(int j = 0; j + node[tmp].t[i] <= K; j++){
                if(dis[tmp][j] + node[tmp].l[i] < dis[node[tmp].d[i]][j + node[tmp].t[i]]){
                    dis[node[tmp].d[i]][j + node[tmp].t[i]] = dis[tmp][j] + node[tmp].l[i];
                    if(!inQueue[node[tmp].d[i]]){
                        q.push(node[tmp].d[i]);
                        inQueue[node[tmp].d[i]] = true;
                    }
                }
            }
        }
    }
}

int main(){
    int S, D, L, T;

    scanf("%d%d%d", &K, &N, &R);
    while(R--){
        scanf("%d%d%d%d", &S, &D, &L, &T);
        node[S].d.push_back(D);
        node[S].l.push_back(L);
        node[S].t.push_back(T);
    }

    SPFA();
    int ans = INF;
    for(int i = 0; i <= K; i++){
        if(dis[N][i] < ans)
        ans = dis[N][i];
    }
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}
