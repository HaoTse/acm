#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct POS{
    int x, y;
}pos[503];

struct EDGE{
    int a, b;
    double len;
}edge[250003];

int p[503];

void ini(int n){
    for(int i = 0; i < n; i++) p[i] = i;
}

int Find(int x){
    return (p[x] == x) ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y){
    p[Find(x)] = Find(y);
}

bool cmp(EDGE a, EDGE b){
    return a.len < b.len;
}

int main(){
    int Case, S, P;

    scanf("%d", &Case);
    while(Case--){
        scanf("%d %d", &S, &P);

        for(int i = 0; i < P; i++){
            scanf("%d %d", &pos[i].x, &pos[i].y);
        }

        int num_edge = 0;
        for(int i = 0; i < P; i++){
            for(int j = i + 1; j < P; j++){
                edge[num_edge].a = i;
                edge[num_edge].b = j;
                edge[num_edge++].len = sqrt(pow(pos[i].x - pos[j].x, 2) + pow(pos[i].y - pos[j].y, 2));
            }
        }

        sort(edge, edge + num_edge, cmp);


        double ans = 0;
        int cnt = 0;
        ini(P);
        for(int i = 0; i < num_edge; i++){
            if(Find(edge[i].a) != Find(edge[i].b)){
                Union(edge[i].a, edge[i].b);
                cnt++;
                if(cnt + S == P){
                    ans = edge[i].len;
                    break;
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
