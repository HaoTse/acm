#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main(){
    map<string, string> m;
    char buf[25];
    char *tmp1, *tmp2;

    while(gets(buf)){
        if(!strcmp(buf, ""))
            break;

        tmp1 = strtok(buf, " ");
        tmp2 = strtok(NULL, " ");

        m[tmp2] = tmp1;
    }

    while(scanf("%s", buf) != EOF){
        if(m[buf] != "")
            printf("%s\n", m[buf].c_str());
        else
            printf("eh\n");
    }

    return 0;
}
