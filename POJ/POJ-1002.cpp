#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char Map[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'};

struct IN{
    char s[9];
};

int cmp(const void *a,const void *b)
{
    return strcmp((*(IN *)a).s, (*(IN *)b).s);
}

int main(){
    int num;
    int i, cur = 0, cnt = 1;
    char buf;
    bool flag = true;

    scanf("%d", &num);
    IN in[num];

    for(i = 0; i < num; i++){
        cur = 0;
        getchar();
        while(cur < 8){
            scanf("%c", &buf);
            if(buf == '-' || buf == 'Q' || buf == 'Z')
                continue;
            else if(buf >= '0' && buf <= '9')
                in[i].s[cur++] = buf;
            else if(buf >= 'A' && buf <= 'Z')
                in[i].s[cur++] = Map[buf - 'A'];
            if(cur == 3)
                in[i].s[cur++] = '-';
        }

        in[i].s[cur] = '\0';
    }

    qsort(in, num, sizeof(char)*9, cmp);

    for(i = 1; i < num; i++){
        if(strcmp(in[i].s, in[i-1].s)){
            if(cnt > 1){
                printf("%s %d\n", in[i - 1].s, cnt);
                flag = false;
            }
            cnt = 0;
        }
        cnt++;
    }

    if(cnt > 1){
        printf("%s %d\n", in[i - 1].s, cnt);
        flag = false;
    }

    if(flag)
        printf("No duplicates.\n");

    return 0;
}
