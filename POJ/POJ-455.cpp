#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int ans = 0;

void build(string a, int *pi){
    int len = a.length();
    pi[0] = -1;
    int cur_pos = -1;
    for(int i = 1; i < len; i++){
        while(cur_pos >= 0 && a[i] != a[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == a[cur_pos + 1]) ++cur_pos;
        pi[i] = cur_pos;
    }
    ans = cur_pos + 1;
}

int main(){
    int N;
    char buf[83];
    int pi[83];

    scanf("%d", &N);
    getchar();
    while(N--){
        getchar();
        gets(buf);

        ans = 0;
        build(buf, pi);

        int len = strlen(buf);
        if(len%(len - ans)) printf("%d\n", len); //when in buile cur_pos = -1 => ans = 0, len - ans = len, so the answer is the all string
        else printf("%d\n", strlen(buf) - ans); //return value is the last repeated characters in the string, ex. abcabcabc will return 5
        if(N) printf("\n");
    }

    return 0;
}
