#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 8

using namespace std;

vector<vector<int> > cheese;
int queen[N];
int column[N] = {0};
int slash[N * 2] = {0};
int backSlash[N * 2] = {0};

void backtracking(int r){
    if(r == N){
        vector<int> tmp(queen, queen + N);
        cheese.push_back(tmp);
        return ;
    }
    for(int i = 0; i < N; i++){
        if(!column[i] && !slash[r + i] && !backSlash[r - i + N]){
            queen[r] = i;
            column[i] = slash[r + i] = backSlash[r - i + N] = 1;
            backtracking(r + 1);
            column[i] = slash[r + i] = backSlash[r - i + N] = 0;
        }
    }
}

int main(){
    int k;
    int board[N][N];

    backtracking(0);

    scanf("%d", &k);
    while(k--){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &board[i][j]);

        int ans = 0;

        for(int i = 0; i < cheese.size(); i++){
            int tmp_sum = 0;
            for(int j = 0; j < N; j++){
                tmp_sum += board[j][cheese[i][j]];
            }
            ans = (ans > tmp_sum) ? ans : tmp_sum;
        }
        printf("%5d\n", ans);
    }

    return 0;
}
