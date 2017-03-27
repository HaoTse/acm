#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

int dfn[100003], low[100003];
vector<int> node[100003];
bool inStack[100003];
stack<int> stk;
int cnt_comp = 0;
int comp[100003];
bool can_arr[100003]; //if a component can arrive the other component

int cnt_dfn = 0;
void tarjan(int n){
    int top;
    low[n] = dfn[n] = ++cnt_dfn;
    stk.push(n);
    inStack[n] = true;
    for(int i = 0; i < node[n].size(); i++){
        if(!dfn[node[n][i]]){
            tarjan(node[n][i]);
            low[n] = (low[n] < low[node[n][i]]) ? low[n] : low[node[n][i]];
        }
        else if(inStack[node[n][i]]){
            low[n] = (low[n] < dfn[node[n][i]]) ? low[n] : dfn[node[n][i]];
        }
    }
    if(low[n] == dfn[n]){
        cnt_comp++;
        can_arr[cnt_comp] = false; //init
        do{
            top = stk.top();
            stk.pop();
            inStack[top] = false;
            comp[top] = cnt_comp;
        } while(top != n);
    }
}

int main(){
    int Case, n, m;

    scanf("%d", &Case);
    while(Case--){
        scanf("%d %d", &n, &m);
        while(!stk.empty())
            stk.pop();
        for(int i = 0; i <= n; i++){
            node[i].clear();
            dfn[i] = low[i] = 0;
            inStack[i] = false;
        }

        int s, u;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &s, &u);
            node[s].push_back(u);
        }

        cnt_dfn = cnt_comp = 0;
        for(int i = 1; i <= n; i++){
            if(!dfn[i]) tarjan(i);
        }
        for(int i = 1; i <= n; i++){
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
        printf("%d\n", ans);
    }

    return 0;
}
