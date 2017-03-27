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
    char buf[1000003];
    int pi[1000003];

    while(gets(buf)){
        if(!strcmp(buf, ".")) break;
        ans = 0;
        build(buf, pi);

        int len = strlen(buf);
        if(len%(len - ans)) printf("1\n"); //when in buile cur_pos = -1 => ans = 0, len - ans = len, so the answer is the all string
        else printf("%d\n", strlen(buf) / (strlen(buf) - ans)); //return value is the last repeated characters in the string, ex. abcabcabc will return 5
    }

    return 0;
}
