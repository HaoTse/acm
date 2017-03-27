#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int dis[103];
int cost[103][103];
bool inQueue[103];

struct ELEV{
    vector<int> d;
    int time;
}elev[5];

void SPFA(int s){
    queue<int> q;
    for(int i = 0; i < 103; i++){
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

        for(int i = 0; i < 103; i++){
            if(dis[now] + cost[now][i] + 60 < dis[i]){
                dis[i] = dis[now] + cost[now][i] + 60;
                if(!inQueue[i]){
                    q.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }
}

int main(){
    int n, k;

    while(scanf("%d%d", &n, &k) != EOF){
        for(int i = 0; i < 103; i++){
            for(int j = 0; j < 103; j++){
                cost[i][j] = INF;
            }
        }
        for(int i = 1; i <= n; i++){
            int t;
            scanf("%d", &t);
            elev[i].time = t;
            elev[i].d.clear();
        }

        getchar();
        for(int i = 1; i <= n; i++){
            char buf[500];
            char *tok;
            gets(buf);

            tok = strtok(buf, " ");
            while(tok != NULL){
                elev[i].d.push_back(atoi(tok));
                tok = strtok(NULL, " ");
            }

            for(int j = 0; j < elev[i].d.size(); j++){
                for(int k = j + 1; k < elev[i].d.size(); k++){
                    int f1 = elev[i].d[j], f2 = elev[i].d[k];
                    cost[f1][f2] = (cost[f1][f2] < (f2 - f1) * elev[i].time) ? cost[f1][f2] : (f2 - f1) * elev[i].time;
                    cost[f2][f1] = (cost[f2][f1] < (f2 - f1) * elev[i].time) ? cost[f2][f1] : (f2 - f1) * elev[i].time;
                }
            }
        }

        SPFA(0);
        if(dis[k] == INF) printf("IMPOSSIBLE\n");
        else if(k == 0) printf("0\n");
        else printf("%d\n", dis[k] - 60); //msut -60, because in SPFA 0 to x is +60
    }
    return 0;
}
