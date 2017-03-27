#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;

map<int, int> m;
int num[200005];
int tmp[200005]; //replace the value when Move
int sum[200005];
int rep; //replace number

void ini(int n){
    for(int i = 1; i <= n; i++){
        m[i] = i;
        sum[i] = i;
        tmp[i] = i;
        num[i] = 1;
    }
    rep = n + 1;
}

int Find(int a){
    return (m[a] == a) ? a : (m[a] = Find(m[a]));
}

void Union(int a, int b){
    num[Find(b)] += num[Find(a)];
    sum[Find(b)] += sum[Find(a)];

    m[Find(a)] = Find(b);
}

void reMove(int a, int b){
    num[Find(tmp[a])]--;
    sum[Find(tmp[a])] -= a;

    //replace
    tmp[a] = rep++;
    m[tmp[a]] = tmp[a];
    num[tmp[a]] = 1;
    sum[tmp[a]] = a;

    Union(tmp[a], tmp[b]);
}

int main(){
    int N, M, n1, n2;
    char buf[20];
    char *token;

    while(scanf("%d %d", &N, &M) != EOF){
        m.clear();
        ini(N);
        getchar();
        while(M--){
            gets(buf);

            token = strtok(buf, " ");
            n1 = atoi(strtok(NULL, " "));

            if(!strcmp(token, "1")){
                n2 = atoi(strtok(NULL, " "));
                if(Find(tmp[n1]) == Find(tmp[n2]))
                    continue;
                Union(tmp[n1], tmp[n2]);
            }
            else if(!strcmp(token, "2")){
                n2 = atoi(strtok(NULL, " "));
                if(Find(tmp[n1]) == Find(tmp[n2]))
                    continue;
                reMove(n1, n2);
            }
            else{
                printf("%d %d\n", num[Find(tmp[n1])], sum[Find(tmp[n1])]);
            }
        }
    }
    return 0;
}
