#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct NODE{
    vector<int> d;
    vector<double> r, c;
}node[103];

double dis[103];
bool inQueue[103];
int N;

void SPFA(int s, double v){
    queue<int> q;
    for(int i = 0; i < N; i++){
        dis[i] = 0;
        inQueue[i] = false;
    }
    dis[s] = v;
    inQueue[s] = true;
    q.push(s);

    while(!q.empty()){
        int now = q.front();
        inQueue[now] = false;
        q.pop();

        for(int i = 0; i < node[now].d.size(); i++){
            double c = node[now].c[i];
            double r = node[now].r[i];
            int nxt = node[now].d[i];
            if((dis[now] - c) * r > dis[nxt]){
                dis[nxt] = (dis[now] - c) * r;
                if(!inQueue[nxt]){
                    q.push(nxt);
                    inQueue[nxt] = true;
                }
            }
        }
    }
}

int main(){
    int M, S;
    double V;

    scanf("%d %d %d %lf", &N, &M, &S, &V);
    int a, b;
    double rab, rba, cab, cba;
    for(int i = 0; i < M; i++){
        scanf("%d %d %lf %lf %lf %lf", &a, &b, &rab, &cab, &rba, &cba);
        node[a].d.push_back(b);
        node[a].r.push_back(rab);
        node[a].c.push_back(cab);
        node[b].d.push_back(a);
        node[b].r.push_back(rba);
        node[b].c.push_back(cba);
    }
    SPFA(S, V);

    if(dis[S] > V) puts("YES");
    else puts("NO");

    return 0;
}
