#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int Case, n, m, tmp;
    int step = 0;
    queue<int> q;
    priority_queue<int> pq;

    scanf("%d", &Case);
    while(Case--){
        step = 0;

        scanf("%d %d", &n, &m);
        while(n--){
            scanf("%d", &tmp);
            q.push(tmp);
            pq.push(tmp);
        }

        while(m >= 0){
            while(q.front() != pq.top()){
                q.push(q.front());
                q.pop();
                m--;
                if(m < 0)
                    m = q.size() - 1;
            }
            q.pop();
            pq.pop();
            step++;
            m--;
        }

        printf("%d\n", step);

        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();
    }

    return 0;
}
