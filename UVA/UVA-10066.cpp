#include <cstdio>

int main(){
    int n1, n2, Case = 1;
    int seq1[103], seq2[103];
    int ans[103][103] = {0};

    while(scanf("%d %d", &n1, &n2) && n1 != 0 && n2 != 0){
        for(int i = 1; i <= n1; i++)
            scanf("%d", &seq1[i]);
        for(int j = 1; j <= n2; j++)
            scanf("%d", &seq2[j]);

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(seq1[i] == seq2[j])
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                else
                    ans[i][j] = (ans[i - 1][j] > ans[i][j - 1]) ? ans[i - 1][j] : ans[i][j - 1];
            }
        }

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", Case++, ans[n1][n2]);
    }
    return 0;
}
