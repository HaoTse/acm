#include <cstdio>
#include <vector>

using namespace std;

int ans[9];
int dir[][4] = { {2, 3, 5}, {1, 3, 5}, {1, 2, 4, 5}, {3, 5}, {1, 2, 3, 4} };
int len[5] = {3, 3, 4, 2, 4};
bool visited[6][6] = {false};

void backtracking(int pos, int n){
    if(n == 9){
        for(int i = 0; i < n; i++){
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    for(int i = 0; i < len[pos - 1]; i++){
        int tmp = dir[pos - 1][i];
        if(!visited[pos][tmp] && !visited[tmp][pos]){
            visited[pos][tmp] = true;
            visited[tmp][pos] = true;

            ans[n] = tmp;
            backtracking(tmp, n + 1);

            visited[pos][tmp] = false;
            visited[tmp][pos] = false;
        }
    }
}

int main(){
    ans[0] = 1;
    backtracking(1, 1);

    return 0;
}
