#include <cstdio>
#include <queue>

using namespace std;

int main(){
    long long num, tmp;
    priority_queue<long long, vector<long long>, greater<long long> > pq;

    while(scanf("%lld", &num) != EOF){
        while(!pq.empty())
            pq.pop();
        long long ans = 0, cost;
        while(num--){
            scanf("%lld", &tmp);
            pq.push(tmp);
        }

        while(pq.size() > 1){
            cost = pq.top();
            pq.pop();
            cost += pq.top();
            pq.pop();
            pq.push(cost);
            ans += cost;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
