#include <cstdio>
#include <cstring>

#define MAXS 1100

using namespace std;

int m[MAXS][MAXS];
int S;

int lowbit(int in){
    return in & (-in);
}

void modify(int x, int y, int delta){
    for(int i = x; i <= S; i += lowbit(i))
        for(int j = y; j <= S; j += lowbit(j))
            m[i][j] += delta;
}

int getsum(int x, int y){
    int ans = 0;
    int i = x, j = y;
    while(i > 0){
        j = y;
        while(j > 0){
            ans += m[i][j];
            j -= lowbit(j);
        }
        i -= lowbit(i);
    }
    return ans;
}

int main(){
    int op;

    while(scanf("%d", &op) && op != 3){
        if(op == 0){
            scanf("%d", &S);
            memset(m, 0, sizeof(m));
        }
        else if(op == 1){
            int X, Y, A;
            scanf("%d %d %d", &X, &Y, &A);
            modify(X + 1, Y + 1, A);
        }
        else if(op == 2){
            int L, B, R, T;
            scanf("%d %d %d %d", &L, &B, &R, &T);
            printf("%d\n", getsum(R + 1, T + 1) - getsum(L, T + 1) - getsum(R + 1, B) + getsum(L, B));
        }
    }

    return 0;
}