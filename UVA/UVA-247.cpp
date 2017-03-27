#include <cstdio>
#include <stack>
#include <vector>
#include <map>
#include <string>

using namespace std;

int low[30], dfn[30];
vector<int> node[30];
vector<int> comp[30];
bool inStack[30];
stack<int> stk;
map<string, int> Map;
string str_record[30];

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
    int n, m, cnt_in;
    int Case = 0;
    char buf1[30], buf2[30];

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0) break;

        //init
        Map.clear();
        while(!stk.empty())
            stk.pop();
        for(int i = 0; i <= n; i++){
            node[i].clear();
            comp[i].clear();
            dfn[i] = low[i] = 0;
            inStack[i] = false;
        }
        cnt_in = 0;

        //input
        for(int i = 0; i < m; i++){
            scanf("%s %s", buf1, buf2);
            if(!Map[buf1]){
                Map[buf1] = ++cnt_in;
                str_record[cnt_in] = buf1;
            }
            if(!Map[buf2]){
                Map[buf2] = ++cnt_in;
                str_record[cnt_in] = buf2;
            }
            node[Map[buf1]].push_back(Map[buf2]);
        }

        //SCC
        cnt_dfn = cnt_comp = 0;
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i);

        if(Case) puts("\n");
        printf("Calling circles for data set %d:\n", ++Case);
        for(int i = 1; i <= cnt_comp; i++){
            for(int j = 0; j < comp[i].size(); j++){
                if(j != comp[i].size() - 1)
                    printf("%s, ", str_record[comp[i][j]].c_str());
                else
                    printf("%s\n", str_record[comp[i][j]].c_str());
            }
        }
    }

    return 0;
}
