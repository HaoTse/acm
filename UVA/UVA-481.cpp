#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a;
    vector<int> in;
    vector<int> tmp;
    vector<int> pre;
    vector<int> out;

    while(scanf("%d", &a) != EOF){
        in.push_back(a);
        pre.push_back(0);
    }

    tmp.push_back(in[0]);
    for(int i = 1; i < in.size(); i++){
        int t = lower_bound(tmp.begin(), tmp.end(), in[i]) - tmp.begin();
        pre[i] = t;
        if(t == tmp.size())
            tmp.push_back(in[i]);
        else
            tmp[t] = in[i];
    }
    printf("%d\n-\n", tmp.size());
    int cur = tmp.size() - 1;
    for(int i = pre.size() - 1; i >= 0; i--){
        if(pre[i] == cur){
            out.push_back(in[i]);
            cur--;
        }
    }
    for(int i = out.size() - 1; i >= 0; i--){
        printf("%d\n", out[i]);
    }

    return 0;
}
