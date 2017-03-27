#include <cstdio>
#include <cstring>

using namespace std;

int in[100] = {0}, ans[100] = {0};
int k;
bool isVisit[100];

void backtracking(int l, int n){
    if(l == 6){
        for(int i = 0; i < 6; i++){
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i = n; i < k; i++){
        if(!isVisit[i]){
            ans[l] = in[i];
            isVisit[i] = true;
            backtracking(l + 1, i + 1);
            isVisit[i] = false;
        }
    }
}

int main(){
    bool f =  false;

    while(scanf("%d", &k)){
        if(k == 0)
            break;
        if(f)
            printf("\n");
        f = true;
        memset(isVisit, false, sizeof(isVisit));
        for(int i = 0; i < k; i++){
            scanf("%d", &in[i]);
        }
        backtracking(0, 0);

    }
    return 0;
}
