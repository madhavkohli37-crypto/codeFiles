// This is the gfg version
/*
A MST is a minimum spanning tree that has the following properties :-
1). It is made for a weighted undirected graph.
2). It should be a tree that is it should be a single component Graph with no cycles such that the weight is minimum.
3). All the vertices should be visited.
*/
class DSU {
	private:
	vector<int>superparent;
	vector<int>rank;
	int totalcomponents;
	public:
	DSU(int n) {
		superparent.resize(n + 1, -1);
		rank.resize(n + 1, 1);
		totalcomponents = n;
	}
	int findS(int node) {
		if (superparent[node] == -1) {
			return node;
		}
		// path compression (DP)
		return superparent[node] = findS(superparent[node]);
	}
	void unionS(int x, int y) {
		// union by rank
		int S1 = findS(x);
		int S2 = findS(y);
		if (S1 != S2) {
			if (rank[S1]<rank[S2]) {
				superparent[S1] = S2;
				rank[S2] += rank[S1];
			}
			else {
				superparent[S2] = S1;
				rank[S1] += rank[S2];
			}
			totalcomponents--;
		}
	}
};
class Solution {
	public:
	static bool compare(vector<int>a, vector<int>b) {
		return (a[2]<b[2]);
	}
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		DSU d(V);
		int ans = 0;
		unordered_map<int, bool>visited;
		sort(edges.begin(), edges.end(), compare);
		for (vector<int>v:edges) {
			int P1 = d.findS(v[0]);
			int P2 = d.findS(v[1]);
			if (P1 != P2) {
				ans += v[2];
				d.unionS(v[0], v[1]);
			}
		}
		return ans;
		
	}
};
