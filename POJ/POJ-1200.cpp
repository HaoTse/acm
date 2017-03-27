#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char str[16000003];
int tmp[125] = {0}; //'z' is 123
bool isFind[16000003];

int main(){
    int n, nc;

    memset(isFind, false, 16000003);
    scanf("%d %d", &n, &nc);
    getchar();
    gets(str);
    int len = strlen(str), ans = 0, cnt = 0;
    for(int i = 0; i < len; i++){
        if(!tmp[str[i]]) tmp[str[i]] = cnt++;
        if(cnt == nc) break;
    }
    for(int i = 0; i <= len - n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum = sum * nc + tmp[str[i + j]];
        }
        if(!isFind[sum]){
            isFind[sum] = true;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
