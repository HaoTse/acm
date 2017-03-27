#include <cstdio>
#include <stack>
#include <vector>
#include <map>
#include <string>

using namespace std;

int low[1003], dfn[1003];
vector<int> node[1003];
vector<int> comp[1003];
bool inStack[1003];
stack<int> stk;
map<string, int> Map;

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
    int p, t, cnt_in;
    int Case = 0;
    char buf1[50], buf2[50];

    while(scanf("%d %d", &p, &t)){
        if(p == 0 && t == 0) break;

        //init
        Map.clear();
        while(!stk.empty())
            stk.pop();
        for(int i = 0; i <= p; i++){
            node[i].clear();
            comp[i].clear();
            dfn[i] = low[i] = 0;
            inStack[i] = false;
        }
        cnt_in = 0;

        //input
        getchar();
        for(int i = 0; i < p; i++){
            gets(buf1);
            Map[buf1] = ++cnt_in;
        }
        for(int i = 0; i < t; i++){
            gets(buf1);
            gets(buf2);
            node[Map[buf1]].push_back(Map[buf2]);
        }

        //SCC
        cnt_dfn = cnt_comp = 0;
        for(int i = 1; i <= p; i++)
            if(!dfn[i]) tarjan(i);

        printf("%d\n", cnt_comp);
    }

    return 0;
}

