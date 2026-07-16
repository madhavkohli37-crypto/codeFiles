// This is the leetcode version
class DSU {
public:
    const long long neg = -1e18;
    unordered_map<int, int> rank;
    unordered_map<int, long long> superparent;
    int findS(int node) {
        if (superparent[node] == neg) {
            return node;
        }
        return superparent[node] = findS(superparent[node]);
    }
    void unionS(int x, int y) {
        int S1 = findS(x);
        int S2 = findS(y);
        if (S1 != S2) {
            if (superparent[S1] > superparent[S2]) {
                superparent[S2] = S1;
                rank[S1] += rank[S2];
            } else {
                superparent[S1] = S2;
                rank[S2] += rank[S1];
            }
        }
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU d;
        for (int x : nums) {
            d.rank[x] = 1;
            d.superparent[x] = d.neg;
        }
        unordered_map<int, bool> visited;
        for (int x : nums) {
            visited[x] = true;
            if (visited[x - 1]) {
                d.unionS(x, x - 1);
            }
            if (visited[x + 1]) {
                d.unionS(x, x + 1);
            }
        }
        int maxi = 0;
        for (unordered_map<int, int>::iterator it = d.rank.begin();
             it != d.rank.end(); it++) {
            if ((*it).second > maxi) {
                maxi = (*it).second;
            }
        }
        return maxi;
    }
};
