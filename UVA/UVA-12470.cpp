#include <cstdio>

#define MOD 1000000009
#define LL long long

LL add(LL a, LL b){
    return (a + b) % MOD;
}

LL mul(LL a, LL b){
    return a * b % MOD;
}

struct Mat{
    LL x[3][3];
    Mat(LL a = 0, LL b = 0, LL c = 0, LL d = 0, LL e = 0, LL f = 0, LL g = 0, LL h = 0, LL i = 0){
        x[0][0] = a; x[0][1] = b; x[0][2] = c; x[1][0] = d; x[1][1] = e; x[1][2] = f; x[2][0] = g; x[2][1] = h; x[2][2] = i;
    }
    Mat operator *(const Mat &A)const{
        Mat res;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    res.x[i][j] = add(res.x[i][j], mul(x[i][k], A.x[k][j]));
        return res;
    }
};

Mat fast(Mat A, LL n){
    Mat res = Mat(1, 0, 0, 0, 1, 0, 0, 0, 1);
    while(n){
        if(n & 1) res = res * A;
        A = A * A;
        n >>= 1;
    }
    return res;
}


int main(){
    LL n;
    LL f0 = 0, f1 = 1, f2 = 2;

    while(scanf("%lld", &n)){
        if(n == 0)
            break;
        if(n == 1){
            printf("%lld\n", f0);
            continue;
        }
        if(n == 2){
            printf("%lld\n", f1);
            continue;
        }
        if(n == 3){
            printf("%lld\n", f2);
            continue;
        }

        Mat ans = fast(Mat(1, 1, 1, 1, 0, 0, 0, 1, 0), n - 3);
        LL out = (mul(ans.x[0][0], f2) + mul(ans.x[0][1], f1) + mul(ans.x[0][2], f0)) % MOD;
        if(out < 0) out += MOD;
        printf("%lld\n", out);
    }
    return 0;
}
