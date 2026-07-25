#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
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
vector<int> extendedGCD(int a, int b) {
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
int32_t main() {
    // cout<<fastexpo(100000000000000,10000000);
    vector<int>useful=extendedGCD(10,4);
    cout<<useful[0]<<" "<<useful[1]<<" "<<useful[2]<<endl;

    }
