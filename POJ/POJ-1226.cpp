#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm> //reverse

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

bool fail(string a, string b, int *pi){
    int lenA = a.length(), lenB = b.length();
    for(int i = 0, cur_pos = -1; i < lenA; i++){
        while(cur_pos >= 0 && a[i] != b[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if(a[i] == b[cur_pos + 1]) ++cur_pos;
        if(cur_pos + 1 == lenB){
            return true;
        }
    }
    return false;
}

int main(){
    int Case, N;
    vector<string> str;
    char buf[103];
    int pi[103], rev_pi[103];

    scanf("%d", &Case);
    int min_len = 199, min_index = -1;
    while(Case--){
        scanf("%d", &N);
        str.clear();
        min_len = 199, min_index = -1;
        for(int i = 0; i < N; i++){
            scanf("%s", buf);
            str.push_back(buf);
            if(strlen(buf) < min_len){
                min_len = strlen(buf);
                min_index = i;
            }
        }

        for(int l = min_len; l >= 0; l--){
            bool ifFind = false;
            for(int i = 0; i + l <= min_len; i++){
                string tmp = str[min_index].substr(i, l);
                string rev = tmp;
                reverse(rev.begin(), rev.end());

                build(tmp, pi);
                build(rev, rev_pi);

                for(int j = 0; j < N; j++){
                    if(!fail(str[j], tmp, pi) && !fail(str[j], rev, rev_pi)) break;
                    if(j == N - 1) ifFind = true;
                }

                if(ifFind) break;
            }
            if(ifFind){
                printf("%d\n", l);
                break;
            }
        }
    }

    return 0;
}
