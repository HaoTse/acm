#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char a[1000], b[1000];
    int aCnt[26], bCnt[26];

    while(gets(a)){
        gets(b);

        memset(aCnt, 0, sizeof(aCnt));
        memset(bCnt, 0, sizeof(bCnt));

        for(int i = 0; i < strlen(a); i++){
            aCnt[a[i] - 'a'] += 1;
        }
        for(int i = 0; i < strlen(b); i++){
            bCnt[b[i] - 'a'] += 1;
        }

        for(int i = 0; i < 26; i++){
            int min = (aCnt[i] < bCnt[i]) ? aCnt[i] : bCnt[i];
            for(int j = 0; j < min; j++)
                printf("%c", i + 'a');
        }
        puts("");
    }

    return 0;
}
