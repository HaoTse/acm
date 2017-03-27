#include <cstdio>
#include <string>

using namespace std;

char str[1000003];
int pi[1000003];

void build(string a){
    int len = a.length();
    pi[0] = -1;
    for(int i = 1, cur_pos = -1; i < len; i++){
        while(cur_pos >= 0 && a[i] != a[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == a[cur_pos + 1]) ++cur_pos;
        pi[i] = cur_pos;

        int times = i - cur_pos;
        if(cur_pos >= 0 && !((i + 1)%times)){
            printf("%d %d\n", (i + 1), (i + 1)/times);
        }
    }
}

int main(){
    int N, Case = 1;

    while(scanf("%d", &N) && N){
        getchar();
        gets(str);
        printf("Test case #%d\n", Case++);
        build(str);
        printf("\n");
    }

    return 0;
}
