#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct IN{
    char input[8];
    char sorted[8];
};

bool cmp(const IN a, const IN b){
    return strcmp(a.input, b.input) < 0;
}

int main(){
    vector<IN> in;
    IN buf;
    char tmp[8];
    int cnt = 0;
    bool flag = true;

    while(scanf("%s", tmp)){
        if(!strcmp(tmp, "XXXXXX"))
            break;

        strcpy(buf.input, tmp);
        strcpy(buf.sorted, tmp);
        sort(buf.sorted, buf.sorted + strlen(buf.sorted));
        in.push_back(buf);
        cnt++;
    }

    sort(in.begin(), in.end(), cmp);

    while(scanf("%s", tmp)){
        if(!strcmp(tmp, "XXXXXX"))
            break;

        flag = true;
        sort(tmp, tmp + strlen(tmp));
        for(int i = 0; i < cnt; i++){
            if(!strcmp(tmp, in[i].sorted)){
                printf("%s\n", in[i].input);
                flag = false;
            }
        }
        if(flag)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }

    return 0;
}
