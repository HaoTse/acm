#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>

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
    int Case;
    char buf[1002];
    char *tmp1, *tmp2;
    map<int, int> cnt;

    scanf("%d", &Case);
    while(Case--){
        m.clear();
        cnt.clear();
        int n;
        scanf("%d", &n);

        ini(n);
        getchar();
        while(gets(buf)){
            if(!strcmp(buf, ""))
                break;

            tmp1 = strtok(buf, " ");
            tmp2 = strtok(NULL, " ");
            Union(atoi(tmp1), atoi(tmp2));
            while(1){
                tmp1 = strtok(NULL, " ");
                if(tmp1 == NULL)
                    break;
                tmp2 = strtok(NULL, " ");
                if(tmp2 == NULL)
                    break;
                Union(atoi(tmp1), atoi(tmp2));
            }
        }

        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->first >= 1 && it->first <= n)
                cnt[Find(it->second)]++;
        }
        printf("%d\n", cnt.size());
        if(Case)
            printf("\n");
    }
    return 0;
}
