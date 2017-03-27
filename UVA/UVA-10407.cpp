#include <cstdio>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

int main(){
    int num;
    vector<int> inputs;

    while(scanf("%d", &num)){
        if(!num) break;

        inputs.clear();
        inputs.push_back(num);
        while(scanf("%d", &num) && num){
            inputs.push_back(num);
        }

        int ans = 0;
        for(int i = 1; i < inputs.size(); i++){
            ans = gcd(inputs[i] - inputs[0], ans);
        }

        printf("%d\n", (ans < 0) ? 0 - ans : ans);
    }

    return 0;
}
