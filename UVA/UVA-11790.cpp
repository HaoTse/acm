#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int Case, N;
    vector<int> seq1, seq2;

    scanf("%d", &Case);
    for(int c = 1; c <= Case; c++){
        scanf("%d", &N);
        seq1.clear();
        seq2.clear();
        for(int i = 0; i < N; i++){
            int tmp;
            scanf("%d", &tmp);
            seq1.push_back(tmp);
        }
        for(int i = 0; i < N; i++){
            int tmp;
            scanf("%d", &tmp);
            seq2.push_back(tmp);
        }

        int lcs[N], lds[N];
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < N; i++){
            lcs[i] = lds[i] = seq2[i];
            for(int j = 0; j < i; j++){
                if(seq1[i] > seq1[j])
                    lcs[i] = (lcs[i] > lcs[j] + seq2[i]) ? lcs[i] : lcs[j] + seq2[i];
                else if(seq1[i] < seq1[j])
                    lds[i] = (lds[i] > lds[j] + seq2[i]) ? lds[i] : lds[j] + seq2[i];
            }
            ans1 = (ans1 > lcs[i]) ? ans1 : lcs[i];
            ans2 = (ans2 > lds[i]) ? ans2 : lds[i];
        }

        if(ans1 >= ans2) printf("Case %d. Increasing (%d). Decreasing (%d).\n", c, ans1, ans2);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", c, ans2, ans1);
    }

    return 0;
}
