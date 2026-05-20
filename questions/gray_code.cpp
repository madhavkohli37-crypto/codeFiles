#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<string>>ans(17,{"0","1"});
void F() {
    ans[0]={"0","1"};
    for(int i=1;i<17;i++) {
        ans[i].clear();
        for(int j=0;j<ans[i-1].size();j++) {
            ans[i].push_back("0"+ans[i-1][j]);
        }
        for(int j=ans[i-1].size()-1;j>=0;j--) {
            ans[i].push_back("1"+ans[i-1][j]);
        }
    }
}
int32_t main() {
    cin>>n;
    F();
    for(int i=0;i<ans[n-1].size();i++) {
        cout<<ans[n-1][i]<<endl;
    }
    return 0;
}
