#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

struct BOX{
    int id;
    vector<int> in;
};

bool cmp(BOX a, BOX b){
    for(int i = 0; i < m; i++){
        if(a.in[i] == b.in[i]) continue;
        return a.in[i] < b.in[i];
    }
    return true;
}

int main(){
    vector<BOX> box;
    int len[31], pre[31];

    while(scanf("%d %d", &n, &m) != EOF){

        box.clear();
        for(int i = 0; i < n; i++){
            int tmp;
            BOX tbox;
            tbox.id = i + 1;

            for(int j = 0; j < m; j++){
                scanf("%d", &tmp);
                tbox.in.push_back(tmp);
            }
            sort(tbox.in.begin(), tbox.in.end());
            box.push_back(tbox);
        }
        sort(box.begin(), box.end(), cmp);

        for(int i = 0; i < n; i++){
            len[i] = 1;
            pre[i] = -1;
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(box[i].in[k] >= box[j].in[k]) break;
                    else if(k != m - 1) continue;
                    if(len[i] + 1 > len[j]){
                        len[j] = len[i] + 1;
                        pre[j] = i;
                    }
                    break;
                }
            }
        }

        int Max = 0, tmp;
        for(int i = 0; i < n; i++){
            if(len[i] >= Max){
                Max = (len[i] > Max) ? len[i] : Max;
                tmp = i;
            }
        }
        printf("%d\n", Max);

        int cur = 0;
        int out[31] = {0};

        do{
            out[cur++] = box[tmp].id;
            tmp = pre[tmp];
        } while(tmp != -1);

        for(int i = cur - 1; i >= 0; i--){
            if(!i) printf("%d\n", out[i]);
            else printf("%d ", out[i]);
        }
    }

    return 0;
}
