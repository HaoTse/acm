#include <cstdio>
#include <cstring>

#define INF 0x3f3f3f3f

int v[203], pre[203];
int cap[203][203], flow[203][203];

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

int FordFulkerson(int n){
    int ret = 0;

    while(1){
        memset(v, 0, sizeof(v));
        if(!DFS(0, n, n)) break;
        ret += FindFlow(0, n, n);
    }
    return ret;
}

int main(){
    int n, m;

    while(scanf("%d", &n) != EOF){
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for(int i = 1; i <= n; i++){
            scanf("%d", &cap[i][i + n]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            cap[a + n][b] = c;
        }
        int B, D;
        scanf("%d%d", &B, &D);
        for(int i = 0; i < B; i++){
            int tmp;
            scanf("%d", &tmp);
            cap[0][tmp] = INF;
        }
        for(int i = 0; i < D; i++){
            int tmp;
            scanf("%d", &tmp);
            cap[tmp + n][n + n + 1] = INF;
        }
        printf("%d\n", FordFulkerson(n + n + 1));
    }
    return 0;
}
