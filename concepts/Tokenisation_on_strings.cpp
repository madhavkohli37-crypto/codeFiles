#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int32_t main() {
   string s;
//    cin>>s; or write
getline(cin,s);
// now to use tokenisation here we need to convert this string to a character array
char*ch= (char*)s.c_str();//now this is the character array converted of s
cout<<ch<<endl;
char*c=strtok(ch," ");
while(c!=nullptr) {
    cout<<c<<endl;
    c=strtok(NULL," ");
}

}
