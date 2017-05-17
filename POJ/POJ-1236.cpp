#include <cstdio>
#include <vector>
#include <stack>

#define MAXN 105

using namespace std;

vector<int> node[MAXN];
stack<int> stk;
bool inStk[MAXN];
int dfn[MAXN], low[MAXN], comp[MAXN];
int cnt_dfn, cnt_comp;

void tarjan(int n){
    dfn[n] = low[n] = ++cnt_dfn;
    stk.push(n);
    inStk[n] = true;

    for(int i = 0; i < node[n].size(); i++){
        int nxt = node[n][i];
        if(!dfn[nxt]){
            tarjan(nxt);
            low[n] = (low[n] < low[nxt]) ? low[n] : low[nxt];
        }
        else if(inStk[nxt]){
            low[n] = (low[n] < dfn[nxt]) ? low[n] : dfn[nxt];
        }
    }

    if(dfn[n] == low[n]){
        int top;
        cnt_comp++;
        do{
            top = stk.top();
            stk.pop();
            inStk[top] = false;
            comp[top] = cnt_comp;
        } while(top != n);
    }
}

int main(){
    int N;
    int cnt_in, cnt_out;
    bool can_beArr[MAXN], can_arr[MAXN];

    //init
    for(int i = 0; i < MAXN; i++){
        dfn[i] = low[i] = comp[i] = 0;
        node[i].clear();
        inStk[i] = can_beArr[i] = can_arr[i] = false;
    }
    cnt_dfn = cnt_comp = 0;

    scanf("%d", &N);
    for(int u = 1, v; u <= N; u++){
        while(scanf("%d", &v) && v != 0){
            node[u].push_back(v);
        }
    }

    for(int i = 1; i <= N; i++){
        if(!dfn[i])
            tarjan(i);
    }

    if(cnt_comp == 1){
        printf("1\n0");
        return 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < node[i].size(); j++){
            int nxt = node[i][j];
            if(comp[i] != comp[nxt]){
                can_beArr[comp[nxt]] = true;
                can_arr[comp[i]] = true;
            }
        }
    }

    cnt_in = cnt_out = 0;
    for(int i = 1; i <= cnt_comp; i++){
        if(!can_beArr[i]) cnt_in++;
        if(!can_arr[i]) cnt_out++;
    }

    printf("%d\n", cnt_in);
    printf("%d\n", (cnt_in > cnt_out) ? cnt_in : cnt_out);

    return 0;
}
