#include <cstdio>
#include <vector>
#include <stack>

#define MAXN 10005

using namespace std;

vector<int> node[MAXN];
stack<int> stk;
int dfn[MAXN], low[MAXN];
bool inStk[MAXN];

int comp[MAXN];
bool can_arr[MAXN];//if a component can arrive the other component
int cnt_comp = 0;
int cnt_dfn = 0; //Use to set dfn

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
        else if(inStk[nxt])
            low[n] = (low[n] < dfn[nxt]) ? low[n] : dfn[nxt];
    }

    if(low[n] == dfn[n]){
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
    int T;

    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        int N, M;
        scanf("%d %d", &N, &M);

        //initial
        while(!stk.empty()) stk.pop();
        for(int i = 0; i <= N; i++){
            node[i].clear();
            inStk[i] = false;
            dfn[i] = low[i] = 0;
            can_arr[i] = false;
        }

        while(M--){
            int a, b;
            scanf("%d %d", &a, &b);
            node[a].push_back(b);
        }

        cnt_dfn = cnt_comp = 0;
        for(int i = 1; i <= N; i++){
            if(!dfn[i]) tarjan(i);
        }

        for(int i = 1; i <= N; i++){
            for(int j = 0; j < node[i].size(); j++){
                int nxt = node[i][j];
                if(comp[i] != comp[nxt])
                    can_arr[comp[nxt]] = true;
            }
        }

        int ans = 0;
        for(int i = 1; i <= cnt_comp; i++){
            if(!can_arr[i]) ans++;
        }

        printf("Case %d: %d\n", c, ans);
    }

    return 0;
}
