#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    char buf[5];

    scanf("%d", &n);
    int num[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    getchar();
    gets(buf);
    sort(num, num + n);

    scanf("%d", &k);

    while(k--){
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", num[tmp - 1]);
    }

    return 0;
}
