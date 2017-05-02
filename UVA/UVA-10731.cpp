#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

#define MAXN 26

using namespace std;

int dfn[MAXN], low[MAXN];
vector<int> node[MAXN];
vector<string> ans;
stack<int> stk;
bool inStk[MAXN];
int cnt_dfn;

void tarjan(int n) {
    dfn[n] = low[n] = cnt_dfn++;
    stk.push(n);
    inStk[n] = true;
    for(int nxt : node[n]){
        if(dfn[nxt] == -1){
            tarjan(nxt);
            low[n] = (low[n] < low[nxt]) ? low[n] : low[nxt];
        }
        else if(inStk[nxt]){
            low[n] = (low[n] < dfn[nxt]) ? low[n] : dfn[nxt];
        }
    }

    if(low[n] == dfn[n]){
        int top;
        string tmp = "";
        do{
            top = stk.top();
            stk.pop();
            inStk[top] = false;
            tmp += char(top + 'A');
        } while(top != n);

        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
}

int main(){
    int n, Case = 0;
    bool appear[MAXN];

    while(scanf("%d", &n) && n != 0){

        //init
        while(!stk.empty()) stk.pop();
        for(int i = 0; i < MAXN; i++){
            node[i].clear();
            dfn[i] = low[i] = -1;
            appear[i] = false;
            inStk[i] = false;
        }
        ans.clear();
        cnt_dfn = 0;

        char buf[30];
        while(n--){
            int a, b[5];
            for(int i = 0; i < 5; i++){
                scanf("%s", buf);
                int tmp = b[i] = buf[0] - 'A';
                appear[tmp] = true;
            }
            scanf("%s", buf);
            a = buf[0] - 'A';
            appear[a] = true;

            for(int i : b){
                if(i == a) continue;
                node[a].push_back(i);
            }
        }

        for(int i = 0; i < MAXN; i++){
            if(appear[i] && dfn[i] == -1)
                tarjan(i);
        }
        sort(ans.begin(), ans.end());

        if(Case++) puts("");
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size() - 1; j++)
                printf("%c ", ans[i][j]);
            printf("%c\n", ans[i][ans[i].size() - 1]);
        }
    }

    return 0;
}
