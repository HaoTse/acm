#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Ele{
    int id;
    int w;
    int IQ;
    Ele(int a, int b, int c){
        id = a, w = b, IQ = c;
    }
};

bool cmp(Ele a, Ele b){
    return a.w <= b.w;
}

int main(){
    vector<Ele> ele;
    int IQ, w, Max, Maxid;

    while(scanf("%d %d", &w, &IQ) != EOF){
        Ele tmp(ele.size() + 1, w, IQ);
        ele.push_back(tmp);
    }

    sort(ele.begin(), ele.end(), cmp);

    int lis[ele.size()];
    int pre[ele.size()];
    for(int i = 0; i < ele.size(); i++){
        lis[i] = 1;
        pre[i] = -1;
    }

    Max = 0, Maxid = -1;
    for(int i = 0; i < ele.size(); i++){
        for(int j = i + 1; j < ele.size(); j++){
            if(ele[i].w < ele[j].w && ele[i].IQ > ele[j].IQ){
                if(lis[i] + 1 > lis[j]){
                    lis[j] = lis[i] + 1;
                    pre[j] = i;
                }
            }
        }
        if(lis[i] > Max){
            Max = lis[i];
            Maxid = i;
        }
    }

    vector<int> out;
    printf("%d\n", Max);
    while(Maxid != -1){
        out.push_back(ele[Maxid].id);
        Maxid = pre[Maxid];
    }
    for(int i = out.size() - 1; i >= 0; i--)
        printf("%d\n", out[i]);

    return 0;
}
