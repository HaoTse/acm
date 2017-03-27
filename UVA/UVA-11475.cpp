#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

void build(string a, int *pi){
    int len = a.length();
    pi[0] = -1;
    for(int i = 1, cur_pos = -1; i < len; i++){
        while(cur_pos >= 0 && a[i] != a[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == a[cur_pos + 1]) ++cur_pos;
        pi[i] = cur_pos;
    }
}

int fail(string a, string b, int *pi){
    int lenA = a.length(), lenB = b.length();
    int cur_pos = -1;
    for(int i = 0; i < lenA; i++){
        while(cur_pos >= 0 && a[i] != b[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == b[cur_pos + 1]) ++cur_pos;
    }
    return cur_pos;
}

int main(){
    char buf[100003], bufR[100003];
    int pi[100003];

    while(gets(buf)){
        int len = strlen(buf);
        for(int i = len - 1, j = 0; i >= 0; i--, j++){
            bufR[j] = buf[i];
        }
        bufR[len] = '\0';

        build(bufR, pi);
        int tmp = fail(buf, bufR, pi);
        printf("%s", buf);
        for(int i = tmp + 1; i < len; i++) printf("%c", bufR[i]);
        printf("\n");
    }
    return 0;
}
