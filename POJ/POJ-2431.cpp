#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N, L, P, ans = 0;
    pair<int , int> m[10005];
    priority_queue<int> pq;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        m[i] = make_pair(a, b);
    }

    scanf("%d %d", &L, &P);
    for(int i = 0; i < N; i++)
        m[i].first = L - m[i].first;
    sort(m, m + N);
    m[N] = make_pair(L, 0);

    for(int i = 0; i <= N; i++){

        while(P < m[i].first){
            if(pq.empty()){
                ans = -1;
                break;
            }
            ans++;
            P += pq.top();
            pq.pop();
        }

        pq.push(m[i].second);

        if(ans == -1)
            break;
    }
    printf("%d\n", ans);

    return 0;
}
