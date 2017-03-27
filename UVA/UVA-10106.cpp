#include <cstdio>
#include <cstring>

void mul(int a[255], int b[255], int c[505]){
    for(int i = 0; i < 255; i++){
        for(int j = 0; j < 255; j++){
            c[i + j] += a[i] * b[j];
        }
    }

    for(int i = 0; i < 504; i++){
        if(i != 503){
            c[i + 2] += c[i] / 100;
            c[i] %= 100;
        }
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
}

int main(){
    char buf1[255], buf2[255];
    int n1[255] = {0}, n2[255] = {0}, ans[505] = {0};
    int cur, i;

    while(gets(buf1)){
        if(!strcmp(buf1, ""))
            break;

        memset(ans, 0, sizeof(ans));
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));

        for(i = 0, cur = strlen(buf1) - 1; i < strlen(buf1); i++, cur--)
            n1[cur] = buf1[i] - '0';

        gets(buf2);
        for(i = 0, cur = strlen(buf2) - 1; i < strlen(buf2); i++, cur--)
            n2[cur] = buf2[i] - '0';

        mul(n1, n2, ans);

        for(i = 504; i >= 0; i--)
            if(ans[i] != 0)
                break;
        i = (i < 0) ? 0 : i;
        for(;i >= 0; i--)
            printf("%d", ans[i]);
        printf("\n");
    }

    return 0;
}
