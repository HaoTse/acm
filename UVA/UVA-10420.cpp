#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num, i;

    scanf("%d", &num);
    string in[num];
    string buf;
    int cnt1 = 0;

    for(i = 0; i < num; i++){
        cin >> in[i];
        getline(cin, buf);
    }

    sort(in, in + num);

    for(i = 1; i < num; i++){

        if(in[i - 1] != in[i]){
            printf("%s %d\n", in[i - 1].c_str(), (i - cnt1));
            cnt1 = i;
        }
    }
    printf("%s %d\n", in[i - 1].c_str(), (i - cnt1));

    return 0;
}
