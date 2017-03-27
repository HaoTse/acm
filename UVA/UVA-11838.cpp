#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int low[2003], dfn[2003];
vector<int> node[2003];
vector<int> comp[2003];
bool inStack[2003];
stack<int> stk;

int cnt_dfn = 0, cnt_comp = 0;
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
        do{
            top = stk.top();
            stk.pop();
            inStack[top] = false;
            comp[cnt_comp].push_back(top);
        } while(top != n);
    }
}

int main(){
    int n, m;

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0) break;

        //init
        while(!stk.empty())
            stk.pop();
        for(int i = 0; i <= n; i++){
            node[i].clear();
            comp[i].clear();
            dfn[i] = low[i] = 0;
            inStack[i] = false;
        }

        //input
        int v, w, p;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &v, &w, &p);
            node[v].push_back(w);
            if(p == 2)
                node[w].push_back(v);
        }

        //SCC
        cnt_dfn = cnt_comp = 0;
        for(int i = 1; i <= n && cnt_comp <= 1; i++)
            if(!dfn[i]) tarjan(i);

        if(cnt_comp == 1) puts("1");
        else puts("0");
    }

    return 0;
}

