#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int dis[103];
int n;

struct NODE{
    vector<int> d;
}node[103];

void SPFA(int s){
    bool inQueue[103];
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dis[i] = -1;
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
            int nxt = node[now].d[i];
            if(dis[now] + 1 > dis[nxt]){
                dis[nxt] = dis[now] + 1;
                if(!inQueue[nxt]){
                    q.push(nxt);
                    inQueue[nxt] = true;
                }
            }
        }
    }
}

int main(){
    int s, p, q;
    int Case = 1;
    while(scanf("%d", &n)){
        if(n == 0) break;

        for(int i = 1; i <= n; i++){
            node[i].d.clear();
        }
        scanf("%d", &s);
        while(scanf("%d%d", &p, &q)){
            if(p == 0 && q == 0) break;
            node[p].d.push_back(q);
        }

        SPFA(s);

        int longest = 0, endnode = -1;
        for(int i = 1; i <= n; i++){
            if(dis[i] > longest){
                longest = dis[i];
                endnode = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", Case++, s, longest, endnode);
    }
    return 0;
}
