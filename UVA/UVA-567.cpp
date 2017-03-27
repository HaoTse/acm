#include <cstdio>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, vector<int> > m;

int BFS(int a, int b){
    queue<int> q;
    map<int, int> visit, cost;
    int tmp;

    q.push(a);
    visit[a] = 1;
    cost[a] = 0;
    while(!q.empty()){
        tmp = q.front();
        q.pop();

        for(int i = 0; i < m[tmp].size(); i++){

            if(visit[m[tmp][i]] != 1){
                q.push(m[tmp][i]);
                cost[m[tmp][i]] = cost[tmp] + 1;
                visit[m[tmp][i]] = 1;
            }
            if(m[tmp][i] == b)
                return cost[m[tmp][i]];
        }
    }
}

int main(){
    int Case = 1, num, line = 1, tmp, a, b;

    while(scanf("%d", &num) != EOF){
        while(num--){
            scanf("%d", &tmp);
            m[line].push_back(tmp);
            m[tmp].push_back(line);
        }
        line++;

        if(line == 20){
            printf("Test Set #%d\n", Case);
            scanf("%d", &tmp);
            while(tmp--){
                scanf("%d %d", &a, &b);
                printf("%2d to %2d: %d\n", a, b, BFS(a, b));
            }
            printf("\n");

            line = 1;
            Case++;
            m.clear();
        }
    }
}
