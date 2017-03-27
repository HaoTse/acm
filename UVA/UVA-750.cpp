#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 8

using namespace std;

int Index;
int queen[N];
int row[N] = {0};
int column[N] = {0};
int slash[N * 2] = {0};
int backSlash[N * 2] = {0};

void backtracking(int c){
    if(c == N){
        printf("%2d     ", ++Index);
        for(int i = 0; i < N; i++){
            printf(" %d", queen[i] + 1);
        }
        puts("");
        return ;
    }
    if(column[c]){
        backtracking(c + 1);
        return ;
    }
    for(int i = 0; i < N; i++){
        if(!row[i] && !slash[c + i] && !backSlash[c - i + N]){
            queen[c] = i;
            column[c] = row[i] = slash[c + i] = backSlash[c - i + N] = 1;
            backtracking(c + 1);
            column[c] = row[i] = slash[c + i] = backSlash[c - i + N] = 0;
        }
    }
}

int main(){
    int k;
    int c, r;
    bool new_line = false;

    scanf("%d", &k);
    while(k--){

        scanf("%d %d", &r, &c);

        if(new_line) puts("");
        new_line = true;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        memset(slash, 0, sizeof(slash));
        memset(backSlash, 0, sizeof(backSlash));
        Index = 0;

        c--, r--;

        column[c] = 1;
        row[r] = 1;
        slash[r + c] = 1;
        backSlash[c - r + N] = 1;
        queen[c] = r;

        backtracking(0);
    }

    return 0;
}
