#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string in1, in2;
    int f1[52] = {0}, f2[52] = {0}, record1[100] = {0}, record2[100] = {0};
    int i, j, cnt = 0;

    getline(cin, in1);
    getline(cin, in2);

    for(i = 0; i < in1.length(); i++){
        if(record1[i])
            continue;
        f1[cnt]++;
        for(j = i +1; j < in1.length(); j++){
            if(in1[i] == in1[j]){
                f1[cnt]++;
                record1[j] = 1;
            }
        }
        cnt++;
    }

    cnt = 0;
    for(i = 0; i < in2.length(); i++){
        if(record2[i])
            continue;
        f2[cnt]++;
        for(j = i + 1; j < in2.length(); j++){
            if(in2[i] == in2[j]){
                f2[cnt]++;
                record2[j] = 1;
            }
        }
        cnt++;
    }

    for(i = 0; i <= 52; i++){

        if(f1[i] == 0)
            continue;
        for(j = 0; j <= 52; j++){
            if(f1[i] == f2[j]){
                f1[i] = 0;
                f2[j] = 0;
                break;
            }
        }

        if(j >= 52){
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}
