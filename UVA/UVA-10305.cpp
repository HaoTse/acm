#include <cstdio>
#include <vector>

#define N 101

using namespace std;

vector<int> Next[N];
vector<int> ans;
bool isConnected[N], isVisited[N];

void backtracking(int n) {
    if(!isVisited[n]){
        isVisited[n] = true;

        for(int i = 0; i < Next[n].size(); i++){
            int ele = Next[n][i];
            if(!isVisited[ele])
                backtracking(ele);
        }

        ans.push_back(n);
    }
}

int main(){
    int m, n;

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0)
            break;

        //inital
        for(int i = 0; i < N; i++){
            Next[i].clear();
            isConnected[i] = isVisited[i] = false;
        }
        ans.clear();

        int tmp = m;
        while(tmp--){
            int i, j;
            scanf("%d %d", &i, &j);
            Next[i].push_back(j);
            isConnected[j] = true;
        }

        for(int i = 1; i <= n; i++){
            if(!isConnected[i])
                backtracking(i);
        }

        for(int i = ans.size() - 1; i >= 0; i--){
            printf("%d", ans[i]);
            if(i)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}
