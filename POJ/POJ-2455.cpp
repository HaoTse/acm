#include <cstdio>
#include <cstring>

#define INF 0x3f3f3f3f

struct EDGE{
    int s, d, len;
}edge[40003];

int cap[203][203], flow[203][203];
int pre[203], v[203]; // v is isVisited

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

        if(cap[tmp][i] - flow[tmp][i] > 0)
            f = (f < cap[tmp][i] - flow[tmp][i]) ? f : cap[tmp][i] - flow[tmp][i];
        else
            f = (f < flow[i][tmp]) ? f : flow[i][tmp];
    }

    for(int i = t; i != s; i = pre[i]){
        int tmp = pre[i];

        if(cap[tmp][i] - flow[tmp][i] > 0)
            flow[tmp][i] += f;
        else
            flow[i][tmp] += f;
    }
    return f;
}

int FordFulkerson(int n, int p, int len){
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    int ret = 0;

    for(int i = 0; i < p; i++){
        if(edge[i].len <= len){
            cap[edge[i].s][edge[i].d] += 1;
            cap[edge[i].d][edge[i].s] += 1;
        }
    }

    while(1){
        memset(v, 0, sizeof(v));
        if(!DFS(1, n, n)) break;
        ret += FindFlow(1, n, n);
    }
    return ret;
}

int main(){
    int N, P, T;
    int left = 0, right = 0;

    scanf("%d%d%d", &N, &P, &T);
    for(int i = 0; i < P; i++){
        scanf("%d%d%d", &edge[i].s, &edge[i].d, &edge[i].len);
        right = (right > edge[i].len) ? right : edge[i].len;
    }

    //Binary search
    int mid;
    while(left != right){
        mid = (left + right) / 2;

        if(FordFulkerson(N, P, mid) >= T) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);

    return 0;
}
