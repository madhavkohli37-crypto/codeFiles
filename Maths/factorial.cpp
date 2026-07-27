#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
bool isPrime(long long n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}
int fastexpo(int a,int exp) {
    int base=a;
    int ans=1;
    while(exp) {
        if(exp&1) {
            ans=(ans%mod * base%mod)%mod;
        }
        exp=(exp>>1);
        base=(base%mod * base%mod)%mod;
    }
    return ans;
}
vector<int> extendedEuclid(int a, int b) {
    if (b == 0)
        return {a, 1, 0};

    vector<int> temp = extendedEuclid(b, a % b);

    int g = temp[0];
    int x1 = temp[1];
    int y1 = temp[2];

    int x = y1;
    int y = x1 - (a / b) * y1;
    return {g, x, y};
}
int gcd(int a,int b) {
    while(b!=0) {
        int c=a;
        a=b;
        b=c%b;
    }
    return a;
}
int MMI(int a,int p) {
    // if p (which is the mod) is prime and gcd(p,a)==1 then MMI of a is a^(p-2)%p;
    // This is the statement of fermat's little theorem(FLT)
    int mmi=0;
    if(gcd(a,p)==1) {
        if(isPrime(p)) {
            // use fermat's little theorem
            mmi=fastexpo(a,p-2) ;
        }
        else {
            mmi=extendedEuclid(a,p)[1];
            mmi=(mmi%p + p)%p;
        }
    }
    else {
        mmi=-1;
    }
    return mmi;
}
int nCr(int n, int r, int fact[], int invFact[]) {
    if (r < 0 || r > n)
        return 0;

    return (((fact[n]%mod * invFact[r]%mod) % mod) * invFact[n-r]%mod) % mod;
}
int32_t main() {
    int n;
    cin>>n;
    int facto[n+1];
    facto[0]=1;
    for(int i=1;i<n+1;i++) {
        facto[i]=(facto[i-1]%mod * i%mod)%mod;
    }
    int invfacto[n+1];//this stores the MMI of facto[i]
    invfacto[0]=1;
    invfacto[1]=1;
    for(int i=2;i<=n;i++) {
        invfacto[i]=MMI(facto[i],mod);
    }
    cout<<nCr(5,2,facto,invfacto)<<endl;
}
