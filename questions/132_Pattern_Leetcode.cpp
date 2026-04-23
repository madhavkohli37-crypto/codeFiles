#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;//this stores all the potential nums[j]
        int third = INT_MIN;//this stores all the potential nums[k]
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true;
            }
            while (!st.empty() and nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
int main() {
  vector<int>nums;
  int x;
  while(cin>>x) {
    nums.push_back(x);
  }
  Solution s;
  cout<<s.find132pattern(nums)<<endl;
  return 0;
}
