#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        map<int, vector<int> > h;
        int tmp;
        int k, v;

        for(int i = 1; i <= n; i++){
            scanf("%d", &tmp);
            h[tmp].push_back(i);
        }

        while(m--){
            scanf("%d %d", &k, &v);
            if(k > h[v].size())
                printf("0\n");
            else
                printf("%d\n", h[v][k - 1]);
        }
    }

    return 0;
}
