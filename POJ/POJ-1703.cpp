#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int self[100005];
int E[100005];

void ini(int n){
    for(int i = 1; i <= n; i++){
        self[i] = i;
        E[i] = 0;
    }
}

int findSelf(int a){
    return (self[a] == a) ? a : (self[a] = findSelf(self[a]));
}

void Union(int a, int b){
    self[findSelf(a)] = findSelf(b);
}

int main(){
    int T, N, M, n1, n2;
    char token;

    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        ini(N);
        while(M--){
            scanf(" %c %d %d", &token, &n1, &n2);

            if(token == 'D'){
                if(E[n1] == 0)
                    E[n1] = findSelf(n2);
                else
                    Union(n2, E[n1]);

                if(E[n2] == 0)
                    E[n2] = findSelf(n1);
                else
                    Union(n1, E[n2]);
            }
            else if(token == 'A'){
                if(findSelf(n1) == findSelf(n2))
                    printf("In the same gang.\n");
                else if(findSelf(n1) == findSelf(E[n2]) || findSelf(E[n1]) == findSelf(n2))
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
