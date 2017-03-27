#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int m, n, tmp;

    while(scanf("%d %d", &m, &n) != EOF){
        int buf[n];
        vector<int> local[n + 1];
        vector<int> value[n + 1];

        for(int i = 1; i <= m; i++){
            int r;
            scanf("%d", &r);

            for(int j = 1; j <= r; j++){
                scanf("%d", &buf[j]);
                local[buf[j]].push_back(i);
            }
            for(int j = 1; j <= r; j++){
                scanf("%d", &tmp);
                value[buf[j]].push_back(tmp);
            }
        }

        printf("%d %d\n", n, m);

        for(int i = 1; i <= n; i++){
            printf("%d", local[i].size());

            for(int j = 0; j < local[i].size(); j++)
                printf(" %d", local[i][j]);
            printf("\n");

            for(int j = 0; j < value[i].size(); j++){
                printf("%d", value[i][j]);
                if(j == value[i].size() - 1)
                    printf("\n");
                else
                    printf(" ");
            }

            if(local[i].empty())
                printf("\n");
        }

    }

    return 0;
}
