/*
O(n^2) must than O(40000), use this way
*/
#include <cstdio>
#include <cstring>

#define MAXN 203

bool isEmpty[MAXN][MAXN] = {true};

bool solve(int x1, int y1, int x2, int y2){
    for(int i = x1 + 1; i <= x2; i++){
        for(int j = y1 + 1; j <= y2; j++){
            if(!isEmpty[i][j]) return false;
        }
    }

    for(int i = x1 + 1; i <= x2; i++){
        for(int j = y1 + 1; j <= y2; j++){
            isEmpty[i][j] = false;
        }
    }
    return true;
}

int main(){
    int Case, n, x1, x2, y1, y2;

    scanf("%d", &Case);

    for(int c = 1; c <= Case; c++){
        scanf("%d", &n);

        memset(isEmpty, true, sizeof(isEmpty));
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(solve(x1 + 100, y1 + 100, x2 + 100, y2 + 100)) ans += (x2 - x1) * (y2 - y1);
        }

        printf("Case %d: %d\n", c, ans);
    }

    return 0;
}
