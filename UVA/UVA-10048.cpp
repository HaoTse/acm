#include <cstdio>

#define INF 0x3f3f3f3f

int dis[103][103];

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    int C, S, Q;
    int Case = 0;

    while(scanf("%d%d%d", &C, &S, &Q)){
        if(C == 0 && S == 0 && Q == 0) break;

        if(Case) puts("");

        for(int i = 1; i <= C; i++){
            for(int j = 1; j <= C; j++)
                dis[i][j] = INF;
            dis[i][i] = 0;
        }

        int c1, c2, d;
        for(int i = 0; i < S; i++){
            scanf("%d%d%d", &c1, &c2, &d);
            dis[c1][c2] = d;
            dis[c2][c1] = d;
        }

        for(int k = 1; k <= C; k++)
            for(int i = 1; i <= C; i++)
                for(int j = 1; j <= C; j++)
                    if(max(dis[i][k], dis[k][j]) < dis[i][j])
                        dis[i][j] = max(dis[i][k], dis[k][j]);
        printf("Case #%d\n", ++Case);
        while(Q--){
            scanf("%d%d", &c1, &c2);
            if(dis[c1][c2] == INF) printf("no path\n");
            else printf("%d\n", dis[c1][c2]);
        }
    }
    return 0;
}
