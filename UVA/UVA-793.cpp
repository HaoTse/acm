#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <string>

using namespace std;

map<int, int> m;

void ini(int n){
    for(int i = 1; i <= n; i++)
        m[i] = i;
}

int Find(int a){
    return (m[a] == a) ? a : (m[a] = Find(m[a]));
}

void Union(int a, int b){
    m[Find(a)] = Find(b);
}

int main(){
    int Case, num, n1, n2, suc, unsuc;
    string type;
    char buf[35];

    scanf("%d", &Case);
    while(Case--){
        suc = 0;
        unsuc = 0;
        m.clear();

        scanf("%d", &num);
        ini(num);

        getchar();
        while(gets(buf)){
            if(!strcmp(buf, ""))
                break;

            type = strtok(buf, " ");
            n1 = atoi(strtok(NULL, " "));
            n2 = atoi(strtok(NULL, " "));

            if(type == "c")
                Union(n1, n2);
            else{
                if(Find(n1) == Find(n2))
                    suc++;
                else
                    unsuc++;
            }
        }
        printf("%d,%d\n", suc, unsuc);
        if(Case)
            printf("\n");
    }

    return 0;
}
