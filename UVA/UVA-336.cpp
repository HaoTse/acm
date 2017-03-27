#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct NODE{
    vector<int> adj;
};

NODE node[10005];
int ans;
map<int, bool> element;
queue<int> q;

void BFS(int s, int TTL){

    ans = 1;
    int cnt = 0, cur;
    int tmp[10005] = {0};

    q.push(s);
    tmp[s] = 1;
    while(!q.empty()){
        cur = q.front();
        q.pop();

        for(int i = 0; i < node[cur].adj.size(); i++){
            if(tmp[node[cur].adj[i]])
                continue;
            q.push(node[cur].adj[i]);
            tmp[node[cur].adj[i]] = tmp[cur] + 1;
            if(tmp[node[cur].adj[i]] <= TTL + 1)
                ans++;
        }
    }
}

int main(){
    int NC, a, b, Case = 1;

    while(scanf("%d", &NC)){
        if(NC == 0)
            break;

        element.clear();
        for(int i = 0; i < 99; i++)
            while(!node[i].adj.empty())
                node[i].adj.pop_back();

        while(NC--){
            scanf("%d %d", &a, &b);
            element[a] = true;
            element[b] = true;
            node[a].adj.push_back(b);
            node[b].adj.push_back(a);
        }

        while(scanf("%d %d", &a, &b)){
            if(a == 0 && b == 0)
                break;
            ans = 0;
            if(!node[a].adj.empty())
                BFS(a, b);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case++, element.size()-ans, a, b);
        }
    }
    return 0;
}
