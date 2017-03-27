#include <cstdio>
#include <cstring>

#define INF 0x3f3f3f3f

int cap[103][103], flow[103][103];
int v[103], pre[103];

bool DFS(int cur, int t, int n){
    v[cur] = 1;
    if(cur == t) return true;
    for(int i = 1; i <= n; i++){
        if(v[i]) continue;

        if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
            pre[i] = cur;
            if(DFS(i, t, n)) return true;
        }
    }
    return false;
}

int FindFlow(int s, int t, int n){
    int f = INF;

    for(int i = t; i != s; i = pre[i]){
        int tmp = pre[i];

        if(cap[tmp][i] - flow[tmp][i] > 0){
            f = (f < cap[tmp][i] - flow[tmp][i]) ? f : cap[tmp][i] - flow[tmp][i];
        }
        else{
            f = (f < flow[i][tmp]) ? f : flow[i][tmp];
        }
    }

    for(int i = t; i != s; i = pre[i]){
        int tmp = pre[i];

        if(cap[tmp][i] - flow[tmp][i] > 0)
            flow[tmp][i] += f;
        else
            flow[i][tmp] -= f;
    }
    return f;
}

int FordFulkerson(int s, int t, int n){
    int ret = 0;

    while(1){
        memset(v, 0, sizeof(v));
        if(!DFS(s, t, n)) break;
        ret += FindFlow(s, t, n);
    }
    return ret;
}

int main(){
    int n, s, t, c;
    int Case = 1;

    while(scanf("%d", &n) && n){
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        scanf("%d %d %d", &s, &t, &c);
        int a, b, wid;
        for(int i = 0; i < c; i++){
            scanf("%d %d %d", &a, &b, &wid);
            cap[a][b] += wid;
            cap[b][a] = cap[a][b];
        }

        printf("Network %d\n", Case++);
        printf("The bandwidth is %d.\n\n", FordFulkerson(s, t, n));
    }
    return 0;
}
