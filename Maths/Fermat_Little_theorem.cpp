#include<iostream>
using namespace std;
#define int long long
int fastexpo(int a,int exp,int mod) {
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
int FLT(int a,int p) {
    // if p (which is the mod) is prime and gcd(p,a)==1 then MMI of a is a^(p-2)%p;
    // This is the statement of fermat's little theorem(FLT)
    int MMI=fastexpo(a,p-2,p);
    return MMI;
}
int32_t main() {
    cout<<fastexpo(5,5,10000000007);
}
