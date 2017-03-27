#include <cstdio>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int dis[13];
int pre[13];
int ni;

struct NODE{
    vector<int> d, c;
}node[13];

void SPFA(int s){
    bool inQueue[13];
    queue<int> q;
    for(int i = 1; i <= ni; i++){
        dis[i] = INF;
        pre[i] = i;
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
                pre[nxt] = now;
                if(!inQueue[nxt]){
                    q.push(nxt);
                    inQueue[nxt] = true;
                }
            }
        }
    }
}

int main(){
    int n, d, c, src, des;
    int Case = 1;
    while(scanf("%d", &ni)){
        if(ni == 0) break;

        for(int i = 1; i <= ni; i++){
            node[i].d.clear();
            node[i].c.clear();
        }

        for(int i = 1; i <= ni; i++){
            scanf("%d", &n);
            while(n--){
                scanf("%d%d", &d, &c);
                node[i].d.push_back(d);
                node[i].c.push_back(c);
            }
        }
        scanf("%d%d", &src, &des);

        SPFA(src);

        printf("Case %d: Path =", Case++);
        int cur = des;
        vector<int> output;
        while(cur != src){
            output.push_back(cur);
            cur = pre[cur];
        }
        output.push_back(src);
        for(int i = output.size() - 1; i >= 0; i--){
            printf(" %d", output[i]);
        }
        printf("; %d second delay\n", dis[des]);
    }
    return 0;
}
