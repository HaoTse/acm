#include <cstdio>

using namespace std;

int main(){
    int num;
    int emp[3];
    int mid;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        scanf("%d %d %d", &emp[0], &emp[1], &emp[2]);
        mid = emp[0];
        if(emp[1] > emp[2])
            mid = (mid < emp[1] && mid > emp[2]) ? mid : (mid > emp[1]) ? emp[1] : emp[2];
        else
            mid = (mid > emp[1] && mid < emp[2]) ? mid : (mid > emp[2]) ? emp[2] : emp[1];
        printf("Case %d: %d\n", i, mid);
    }
    return 0;
}
