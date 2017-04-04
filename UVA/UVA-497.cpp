#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

vector<int> data;
vector<int> LIS;
vector<int> pre;
vector<int> ans;

void Find_LIS(){
    int i, j;
    for(i = 0; i < data.size(); i++){
        LIS.push_back(1);
        pre.push_back(i);
        for(j = 0; j < i; j++){
            if(data[j] < data[i] && LIS[j] + 1 > LIS[i]){
                LIS[i] = LIS[j] + 1;
                pre[i] = j;
            }
        }
    }
}

int main(){
    char buf[101];
    int n;

    scanf("%d", &n);
    getchar();
    getchar();
    while(n--){
        data.clear();
        LIS.clear();
        pre.clear();
        ans.clear();

        while(gets(buf) && strcmp(buf, "")){
            data.push_back(atoi(buf));
        }
        Find_LIS();

        int max = 0;
        for(int i = 1; i < data.size(); i++){
            if(LIS[i] > LIS[max])
                max = i;
        }
        printf("Max hits: %d\n", LIS[max]);

        while(max != pre[max]){
            ans.push_back(data[max]);
            max = pre[max];
        };
        ans.push_back(data[max]);

        for(int i = ans.size() - 1; i >= 0; i--){
            printf("%d\n", ans[i]);
        }
        if(n) puts("");
    }

    return 0;
}
