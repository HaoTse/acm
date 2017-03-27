#include <cstdio>
#include <queue>

#define LIMIT 35

using namespace std;

char in[LIMIT][LIMIT][LIMIT] = {'#'};
int d[LIMIT][LIMIT][LIMIT] = {0};
int num, row, col;
int dir[6][3] = { {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0} };
int ans = -1;

struct local{
    int k;
    int i;
    int j;
};

bool outBound(int k, int i, int j){
    return (k >= 0 && i >= 0 && j >= 0 && k < num && i < row && j < col);
}

void BFS(int k, int i, int j){
    queue<local> q;
    local tmp;
    int nk, ni, nj;

    in[k][i][j] = '#';
    tmp.k = k;
    tmp.i = i;
    tmp.j = j;
    q.push(tmp);

    while(!q.empty()){
        local cur = q.front();
        q.pop();

        for(int s = 0; s < 6; s++){
            nk = cur.k + dir[s][0];
            ni = cur.i + dir[s][1];
            nj = cur.j + dir[s][2];

            if(outBound(nk, ni, nj) && in[nk][ni][nj] != '#'){
                d[nk][ni][nj] = d[cur.k][cur.i][cur.j] + 1;
                if(in[nk][ni][nj] == 'E'){
                    in[nk][ni][nj] = '#';
                    ans = d[nk][ni][nj];
                    break;
                }
                in[nk][ni][nj] = '#';
                tmp.k = nk;
                tmp.i = ni;
                tmp.j = nj;
                q.push(tmp);
            }
        }
    }
}

int main(){

    while(scanf("%d %d %d", &num, &row, &col)){

        if(num == 0 && row == 0 && col == 0)
            break;

        ans = -1;
        for(int k = 0; k < LIMIT; k++)
            for(int i = 0; i < LIMIT; i ++)
                for(int j = 0; j < LIMIT; j++){
                    d[k][i][j] = 0;
                    in[k][i][j] = '#';
                }

        for(int k = 0; k < num; k++){

            getchar();
            for(int i = 0; i < row; i++)
                gets(in[k][i]);
        }

        for(int k = 0; k < num; k++){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(in[k][i][j] == 'S')
                        BFS(k, i, j);
                }
            }
        }

        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);

    }

    return 0;
}
