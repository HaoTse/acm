#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);
    int out[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &out[i]);
    }

    sort(out, out + n);

    printf("%d\n", out[n / 2]);

    return 0;
}
