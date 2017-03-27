#include <cstdio>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int dis[20003];
bool inQueue[20003];
int n;

struct NODE{
    vector<int> d, c;
}node[20003];

void SPFA(int s){
    queue<int> q;
    for(int i = 0; i < n; i++){
        dis[i] = INF;
        inQueue[i] = false;
    }
    dis[s] = 0;
    inQueue[s] = true;
    q.push(s);

    while(!q.empty()){
        int now = q.front();
        inQueue[now] = false;
        q.pop();

        for(int i = 0; i < node[now].d.size(); i++){
            int cost = node[now].c[i];
            int nxt = node[now].d[i];
            if(dis[now] + cost < dis[nxt]){
                dis[nxt] = dis[now] + cost;
                if(!inQueue[nxt]){
                    q.push(nxt);
                    inQueue[nxt] = true;
                }
            }
        }
    }
}

int main(){
    int Case, m, s, t;

    scanf("%d", &Case);
    for(int c = 1; c <= Case; c++){
        for(int i = 0; i < n; i++){
            node[i].d.clear();
            node[i].c.clear();
        }
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for(int i = 0; i < m; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            node[x].d.push_back(y);
            node[x].c.push_back(z);
            node[y].d.push_back(x);
            node[y].c.push_back(z);
        }

        SPFA(s);

        printf("Case #%d: ", c);
        if(dis[t] == INF) printf("unreachable\n");
        else printf("%d\n", dis[t]);
    }
    return 0;
}
