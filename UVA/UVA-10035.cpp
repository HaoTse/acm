#include <cstdio>
#include <cstring>

int add(int a[20], int b[20]){
    int c[20] = {0};
    for(int i = 0; i < 20; i++)
        c[i] = a[i] + b[i];
    int ans = 0;

    for(int i = 0; i < 20 - 1; i++){
        ans = ((c[i] / 10) != 0) ? ans + 1 : ans;
        c[i + 1] += c[i] / 10;
        c[i] = c[i] % 10;
    }
    return ans;
}

int main(){
    char buf[30];
    char *token1, *token2;

    while(gets(buf)){
        if(!strcmp(buf, "0 0"))
            break;

        int n1[20] = {0}, n2[20] = {0};
        token1 = strtok(buf, " ");
        token2 = strtok(NULL, " ");

        for(int i = strlen(token1) - 1, j = 0; i >= 0; i--, j++)
            n1[j] = token1[i] - '0';
        for(int i = strlen(token2) - 1, j = 0; i >= 0; i--, j++)
            n2[j] = token2[i] - '0';

        int ans = add(n1, n2);
        (ans == 0) ? printf("No carry operation.\n") : (ans == 1) ? printf("%d carry operation.\n", ans) : printf("%d carry operations.\n", ans);
    }

    return 0;
}
