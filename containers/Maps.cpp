#include <iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<utility>
using namespace std;
int main() {
    map<string,int>mp;
    unordered_map<string,int>ump;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        int x;
        cin>>s>>x;
        pair<string,int>p=make_pair(s,x);
        //currently we are only inserting so duplicate key would not effect anything
        // because a unique key only does once in the map
        // but the value of the key can be updated anytime
        /*
        input data:-
                    4
            Madhav 500
            Jyoti 100
            Pawan 300
            Madhav 300
        */
        // mp.insert(p);
        // ump.insert(p);
        //now we are actually updating 
        //we are able to do this because by default every key of the map has value 0 so we can actually update it
        mp[s]=x;//currently the unordered map will be empty because we never actually
        // inserted in it
        ump[s]=x;
    }
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl<<"---------\n"<<endl;
    for(pair<string,int>x:ump) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}
