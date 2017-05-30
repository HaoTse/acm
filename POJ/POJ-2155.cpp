#include <cstdio>
#include <cstring>

#define MAXN 1005

using namespace std;

int A[MAXN][MAXN];
int N;

int lowbit(int in){
    return in & (-in);
}

int getsum(int x, int y){
    int ans = 0;
    for(int i = x; i <= N; i += lowbit(i))
        for(int j = y; j <= N; j += lowbit(j))
            ans += A[i][j];
    return ans % 2;
    //Except (x, y), other digit will add even times.
    //So the even or odd of ans is the same as (x, y).
}

void modify(int x, int y){
    int i = x, j = y;
    while(i > 0){
        j = y;
        while(j > 0){
            A[i][j]++;
            A[i][j] %= 2;
            j -= lowbit(j);
        }
        i -= lowbit(i);
    }
}

int main(){
    int X;

    scanf("%d", &X);
    while(X--){
        int T;
        char op;
        scanf("%d %d", &N, &T);
        memset(A, 0, sizeof(A));
        while(T--){
            getchar();
            scanf("%c", &op);
            if(op == 'C'){
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                modify(x2, y2);
                modify(x1 - 1, y2);
                modify(x2, y1 - 1);
                modify(x1 - 1, y1 - 1);
            }
            else if(op == 'Q'){
                int x, y;
                scanf("%d %d", &x, &y);
                printf("%d\n", getsum(x, y));
            }
        }
        puts("");
    }

    return 0;
}