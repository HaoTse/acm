#include <cstdio>

long long MOD;

long long add(long long a, long long b){
    return (a + b) % MOD;
}

long long mul(long long a, long long b){
    return a * b % MOD;
}

struct Mat{
    long long x[2][2];
    Mat(long long a = 0, long long b = 0, long long c = 0, long long d = 0){
        x[0][0] = a; x[0][1] = b; x[1][0] = c; x[1][1] = d;
    }
    Mat operator *(const Mat &A)const{
        Mat res;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    res.x[i][j] = add(res.x[i][j], mul(x[i][k], A.x[k][j]));
        return res;
    }
};

Mat fast(Mat A, long long n){
    Mat res = Mat(1, 0, 0, 1);
    while(n){
        if(n & 1) res = res * A;
        A = A * A;
        n >>= 1;
    }
    return res;
}

int main(){
    int m;
    long long n, f0 = 0, f1 = 1;

    while(scanf("%lld %d", &n, &m) != EOF){
        if(n == 0){
            printf("0\n");
            continue;
        }
        MOD = 1 << m;
        Mat ans = fast(Mat(1, 1, 1, 0), n - 1);
        long long out = add(mul(ans.x[0][0], f1), mul(ans.x[0][1], f0));
        if(out < 0) out += MOD;
        printf("%lld\n", out);
    }
    return 0;
}
