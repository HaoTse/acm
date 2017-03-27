#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 503

using namespace std;

int llink[MAXN], rlink[MAXN];
bool used[MAXN];
vector<int> List[MAXN];

struct MAN{
    int h;
    char music[103], sport[103];
}male[MAXN], female[MAXN];

bool DFS(int now){
    int i, next;
    for(int i = 0; i < List[now].size(); i++){
        next =List[now][i];
        if(!used[next]){
            used[next] = true;
            if(!rlink[next] || DFS(rlink[next])){
                rlink[next] = now;
                llink[now] = next;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int L){
    int ret = 0;
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
    for(int i = 1; i <= L; i++){
        memset(used, false, sizeof(used));
        if(DFS(i))
            ret++;
    }
    return ret;
}

int fabs(int a, int b){
    return ((a - b) > 0) ? (a - b) : (b - a);
}

bool cmp(MAN a, MAN b){
    return (fabs(a.h, b.h) <= 40 && !strcmp(a.music, b.music) && strcmp(a.sport, b.sport));
}

int main(){
    int t, n, h;
    char buf1[3], buf2[103], buf3[103];

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(int i = 0; i <= n; i++)
            List[i].clear();

        int cnt_M = 0, cnt_F = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %s %s %s", &h, buf1, buf2, buf3);
            if(!strcmp(buf1, "M")){
                male[++cnt_M].h = h;
                strcpy(male[cnt_M].music, buf2);
                strcpy(male[cnt_M].sport, buf3);
            }
            else{
                female[++cnt_F].h = h;
                strcpy(female[cnt_F].music, buf2);
                strcpy(female[cnt_F].sport, buf3);
            }
        }
        for(int i = 1; i <= cnt_M; i++){
            for(int j = 1; j <= cnt_F; j++){
                if(cmp(male[i], female[j]))
                    List[i].push_back(j);
            }
        }

        printf("%d\n", n - bipartite(n));
    }

    return 0;
}


