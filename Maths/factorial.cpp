/*
Concepts we will be studying :-
1). Modulus
2). Fast exponent
3). Euclid
4). Extended Euclid
5). MMI(Multiplicative Modulo Inverse).
6). Modulo Under Division
7). Fermat's Little Theorem
8). Factorial 
9). Factorial under Modulus.
10). Prime number
*/
#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int mod=1e9+7;
int isPrime(int n) {
    if(n<2) {
        return false;
    }
    if(n==2) {
        return true;
    }
    if(n%2==0) {
        return false;
    }
    for(int i=3;i*i<=n;i+=2) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
    int Modulus_subtraction(int x,int y) {
        int ans = (x%mod - y%mod + mod) % mod;
        return ans;
    }
    int Modulus_addition(int x,int y) {
        int ans = (x%mod + y%mod) % mod;
        return ans;
    }
   int Modulus_Multiplication(int x,int y) {
        int ans = (x%mod * y%mod) % mod;
        return ans;
    }
    int fastexponent(int a,int exp) {
        int ans=1;
        int base=a;
        while(exp) {
            if(exp&1) {
                ans = Modulus_Multiplication(ans,base);
            }
            base = Modulus_Multiplication(base,base);
            exp = exp>>1;
        } 
        return ans;
    }
    int gcd(int a,int b) {
        // GCD using euclid dision lemma
        while(b!=0) {
            int c = a;
             a = b;
             b = c%a;
        }
        return a;
    }
    vector<int> extendedGCD(int a, int b) {
        // lets say it returns a vector v
        // v[0]=gcd of a,b;
        // for eqution ax+by=gcd;
        // v[1]=x; which is the Multiplicative modulo inverse of a under modulus mod
        // v[2]=y; which is the Multiplicative modulo inverse of b under modulus mod
    if (b == 0)
        return {a, 1, 0};

    vector<int> temp = extendedGCD(b, a % b);

    int g = temp[0];
    int x1 = temp[1];
    int y1 = temp[2];

    int x = y1;
    int y = x1 - (a / b) * y1;
    return {g, x, y};
}
int MMI(int x) {
    int mmi;
    if(gcd(x,mod)==1) {
        if(isPrime(x)) {
            // MMI is to be calculated by Fermat's Little Theorem.
            mmi=fastexponent(x,mod-2)%mod ;
        }
        else {
            mmi=extendedGCD(x,mod)[1];
            mmi=(mmi%mod + mod)%mod;
        }
    }
    else {
        // MMI of x does not exists under modulus mod
        return -1;
    }
    return mmi;
}
    int Modulus_Division(int x,int y) {
        // calculate the mmi for y under mod;
        int m=MMI(y);
        return Modulus_Multiplication(x,m);
    }
    int nCr(int n,int r,int facto[],int invfacto[]) {
        if(r>n) {
            return -1;
        }
        int ans = ((facto[n]%mod * invfacto[n-r]%mod) * facto[r]%mod )%mod;
        return ans;
    }
int32_t main() {
    cout<<fastexponent(4,5000000000)<<endl;
    cout<<gcd(4,8)<<endl;
    cout<<MMI(5)<<endl;
    int n;
    cin>>n;
    int facto[n+1];
    int invfacto[n+1];
    facto[0]=1;
    facto[1]=1;
    invfacto[0]=1;
    invfacto[1]=1;
    for(int i=2;i<=n;i++) {
        facto[i]=Modulus_Multiplication(facto[i-1],i);
    }
    for(int i=2;i<=n;i++) {
        invfacto[i]=MMI(facto[i]);
    }
    cout<<nCr(5,1,facto,invfacto)<<endl;
}
