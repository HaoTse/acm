#include <cstdio>

#define MAX_SIZE 30

char in[MAX_SIZE][MAX_SIZE];
int s;
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

bool outBound(int i, int j){
    return (i >= 0 && j >= 0 && i < s && j < s);
}

void DFS(int i, int j){
    in[i][j] = '0';
    int nx, ny;

    for(int k = 0; k < 8; k++){
        nx = i + dir[k][0];
        ny = j + dir[k][1];
        if(outBound(nx, ny) && in[nx][ny] == '1')
            DFS(nx, ny);
    }
}

int main(){
    int c = 0, ans = 0;

    while(scanf("%d", &s) != EOF){
        c++;
        ans = 0;

        scanf("\n");
        for(int i = 0; i < s; i++){
            gets(in[i]);
        }

        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                if(in[i][j] == '1'){
                    DFS(i, j);
                    ans++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", c, ans);
    }
    return 0;
}
