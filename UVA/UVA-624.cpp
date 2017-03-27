#include <cstdio>
#include <vector>

using namespace std;

vector<int> ans;
vector<int> tmp;
int track[21];
int n, m, sum;

void backtracking(int pos, int s){
    if(s > sum){
        ans = tmp;
        sum = s;
    }

    for(int i = pos; i < m; i++){
        if(track[i] + s <= n){
            tmp.push_back(track[i]);

            backtracking(i + 1, s + track[i]);

            tmp.pop_back();
        }
    }
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        sum = 0;
        ans.clear();
        tmp.clear();

        for(int i = 0; i < m; i++)
            scanf("%d", &track[i]);

        backtracking(0, 0);

        for(int i : ans){
            printf("%d ", i);
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}
