#include <cstdio>

#define INF 0x3f3f3f3f

int dis[103][103];

int main(){
    int N, t;

    while(scanf("%d", &N)){
        if(N == 0) break;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++)
                dis[i][j] = INF;
            dis[i][i] = 0;
        }

        for(int i = 1; i <= N; i++){
            scanf("%d", &t);
            while(t--){
                int a, b;
                scanf("%d %d", &a, &b);
                dis[i][a] = b;
            }
        }

        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    if(dis[i][k] + dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k] + dis[k][j];

        int ans_min = INF, ans_pos, max_len;
        bool ans_dis = true, reach;
        for(int i = 1; i <= N; i++){
            max_len = 0;
            reach = true;
            for(int j = 1; j <= N; j++){
                if(dis[i][j] == INF){
                    reach = false;
                    break;
                }
                if(dis[i][j] > max_len)
                    max_len = dis[i][j];
            }
            if(reach){
                ans_dis = false;
                if(ans_min > max_len){
                    ans_min = max_len;
                    ans_pos = i;
                }
            }
        }
        if(!ans_dis) printf("%d %d\n", ans_pos, ans_min);
        else printf("disjoint\n");
    }
    return 0;
}
