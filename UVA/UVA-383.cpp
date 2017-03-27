#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

map<string, vector<string> > m;

int BFS(string a, string b){
    queue<string> q;
    map<string, int> cost, visit;

    q.push(a);
    cost[a] = 0;
    visit[a] = 1;
    while(!q.empty()){
        string tmp = q.front();
        q.pop();

        for(int i = 0; i < m[tmp].size(); i++){

            if(visit[m[tmp][i]] != 1){
                q.push(m[tmp][i]);
                cost[m[tmp][i]] = (cost[m[tmp][i]] < cost[tmp] + 1 && cost[m[tmp][i]] != 0) ? cost[m[tmp][i]] : cost[tmp] + 1;
                visit[m[tmp][i]] = 1;
            }
            if(m[tmp][i] == b)
                return cost[m[tmp][i]];
        }
    }

    return -1;
}

int main(){
    int Case, M, N, P, req, ans;
    char buf[100];
    char *token1, *token2;

    scanf("%d", &Case);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int c = 1; c <= Case; c++){
        printf("DATA SET  %d\n\n", c);
        m.clear();
        scanf("%d %d %d", &M, &N, &P);
        getchar();
        gets(buf);

        while(N--){
            gets(buf);
            token1 = strtok(buf, " ");
            token2 = strtok(NULL, " ");
            m[token1].push_back(token2);
            m[token2].push_back(token1);
        }

        while(P--){
            gets(buf);
            req = atoi(strtok(buf, " "));
            token1 = strtok(NULL, " ");
            token2 = strtok(NULL, " ");
            ans = BFS(token1, token2);
            (ans == -1) ? printf("NO SHIPMENT POSSIBLE\n") : printf("$%d\n", ans*req*100);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
