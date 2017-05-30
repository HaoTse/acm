#include <cstdio>
#include <algorithm>

#define MAXN 503
#define INF 0x3f3f3f3f

using namespace std;

int C[MAXN][MAXN];
int Max[MAXN][MAXN * 4], Min[MAXN][MAXN * 4];
int ans_max, ans_min;

void build(int row, int col, int L, int R){
    if(L == R){
        Max[row][col] = Min[row][col] = C[row][L];
        return ;
    }

    int mid = (L + R) >> 1;
    int tmp = col << 1;
    build(row, tmp, L, mid);
    build(row, tmp + 1, mid + 1, R);
    
    Max[row][col] = max(Max[row][tmp], Max[row][tmp + 1]);
    Min[row][col] = min(Min[row][tmp], Min[row][tmp + 1]);
}

void query(int row, int col, int L, int R, int y1, int y2){
    if(L > y2 || R < y1)
        return ;
    if(L >= y1 && R <= y2){
        ans_max = max(ans_max, Max[row][col]);
        ans_min = min(ans_min, Min[row][col]);
        return ;
    }

    int mid = (L + R) >> 1;
    int tmp = col << 1;
    query(row, tmp, L, mid, y1, y2);
    query(row, tmp + 1, mid + 1, R, y1, y2);
}

void modify(int row, int col, int L, int R, int y, int v){
    if(L > y || R < y)
        return ;
    if(L == y && R == y){
        Max[row][col] = Min[row][col] = v;
        return ;
    }

    int mid = (L + R) >> 1;
    int tmp = col << 1;
    modify(row, tmp, L, mid, y, v);
    modify(row, tmp + 1, mid + 1, R, y, v);

    Max[row][col] = max(Max[row][tmp], Max[row][tmp + 1]);
    Min[row][col] = min(Min[row][tmp], Min[row][tmp + 1]);
}

int main(){
    int N, Q;

    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &C[i][j]);
        }
        build(i, 1, 1, N);
    }
    scanf("%d", &Q);
    while(Q--){
        char type;
        getchar();
        scanf("%c", &type);
        if(type == 'q'){
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ans_max = 0;
            ans_min = INF;
            for(int i = x1; i <= x2; i++){
                query(i, 1, 1, N, y1, y2);
            }
            printf("%d %d\n", ans_max, ans_min);
        }
        else if(type == 'c'){
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            modify(x, 1, 1, N, y, v);
        }
    }

    return 0;
}