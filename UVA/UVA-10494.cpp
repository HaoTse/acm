#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main(){
    char buf[1015];
    string first, op;
    long long sec;

    while(gets(buf)){
        if(!strcmp(buf, ""))
            break;

        int ans[1001] = {0};
        int len = 0, i;
        long long r = 0;

        first = strtok(buf, " ");
        op = strtok(NULL, " ");
        sec = atoi(strtok(NULL, " "));

        for(i = 0; i < first.length(); i++){
            r = r * 10 + (first[i] - '0');
            ans[len++] = r / sec;
            r = r % sec;
        }

        if(op == "/"){
            for(i = 0; i < len; i++)
                if(ans[i] != 0)
                    break;
            if(i == len)
                printf("0\n");
            else{
                for(; i < len; i++)
                    printf("%d", ans[i]);
                printf("\n");
            }
        }
        else
            printf("%lld\n", r);
    }

    return 0;
}
