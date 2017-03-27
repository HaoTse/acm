#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    int n, i;
    char tmp[130];
    stack<char> stk;
    bool flag;

    scanf("%d", &n);
    getchar();
    while(n--){
        flag = true;
        gets(tmp);

        for(i = 0; i < strlen(tmp); i++){
            if(tmp[i] == '(' || tmp[i] == '[')
                stk.push(tmp[i]);
            else if(tmp[i] == ')'){
                if(stk.empty() || stk.top() != '('){
                    flag = false;
                    break;
                }
                stk.pop();
            }
            else if(tmp[i] == ']'){
                if(stk.empty() || stk.top() != '['){
                    flag = false;
                    break;
                }
                stk.pop();
            }
        }

        if(!stk.empty())
            flag = false;
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");

        while(!stk.empty())
            stk.pop();
    }

    return 0;
}
