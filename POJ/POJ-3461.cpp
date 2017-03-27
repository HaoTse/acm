#include <cstdio>
#include <string>

using namespace std;

int ans = 0;

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

void fail(string a, string b, int *pi){
    int lenA = a.length(), lenB = b.length();
    for(int i = 0, cur_pos = -1; i < lenA; i++){
        while(cur_pos >= 0 && a[i] != b[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == b[cur_pos + 1]) ++cur_pos;
        if(cur_pos + 1 == lenB){
            ans++;
            cur_pos = pi[cur_pos];
        }
    }
}

int main(){
    int Case;
    char buf1[10003], buf2[1000003];
    int pi[10003];

    scanf("%d", &Case);
    getchar();
    while(Case--){
        gets(buf1);
        gets(buf2);
        ans = 0;
        build(buf1, pi);
        fail(buf2, buf1, pi);
        printf("%d\n", ans);
    }
    return 0;
}
