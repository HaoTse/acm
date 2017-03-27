#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n, tmp1, tmp2;
    bool flag[3] = {true};
    stack<int> stk;
    queue<int> q;
    priority_queue<int> pq;

    while(scanf("%d", &n) != EOF){
        flag[0] = true;
        flag[1] = true;
        flag[2] = true;

        while(n--){
            scanf("%d %d", &tmp1, &tmp2);
            if(tmp1 == 1){
                stk.push(tmp2);
                q.push(tmp2);
                pq.push(tmp2);
            }
            else{
                if(stk.empty() || tmp2 != stk.top())
                    flag[0] = false;
                if(q.empty() || tmp2 != q.front())
                    flag[1] = false;
                if(pq.empty() || tmp2 != pq.top())
                    flag[2] = false;
                if(!stk.empty())
                    stk.pop();
                if(!q.empty())
                    q.pop();
                if(!pq.empty())
                    pq.pop();
            }
        }

        if(flag[0] || flag[1] || flag[2]){
            if(flag[0] && !flag[1] && !flag[2])
                printf("stack\n");
            else if(!flag[0] && flag[1] && !flag[2])
                printf("queue\n");
            else if(!flag[0] && !flag[1] && flag[2])
                printf("priority queue\n");
            else
                printf("not sure\n");
        }
        else
            printf("impossible\n");

        while(!stk.empty())
            stk.pop();
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();

    }
    return 0;
}
