#include <cstdio>
#include <cstring>

int main(){
    char s1[101], s2[101];
    int ans[101][101] = {0};
    int Case = 1;

    while(gets(s1)){
        if(!strcmp(s1, "#")) break;

        gets(s2);

        for(int i = 1; i <= strlen(s1); i++){
            for(int j = 1; j <= strlen(s2); j++){
                if(s1[i - 1] == s2[j - 1])
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                else
                    ans[i][j] = (ans[i - 1][j] > ans[i][j - 1]) ? ans[i - 1][j] : ans[i][j - 1];
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", Case++, ans[strlen(s1)][strlen(s2)]);
    }

    return 0;
}

