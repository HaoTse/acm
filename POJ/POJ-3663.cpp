#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, s, ans = 0;

    scanf("%d %d", &n, &s);
    int l[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &l[i]);

    sort(l, l + n);

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(l[i] + l[j] <= s)
                ans++;
            else
                break;
        }
    }
    printf("%d\n", ans);

    return 0;
}
