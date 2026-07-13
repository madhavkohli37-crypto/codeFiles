// This is also known as Kahn's Algorithm
class Solution {
	public:
	vector<int>ans;
	private:
	vector<vector<int>> mp = vector<vector<int>> (5005, vector<int> {});
	vector<bool>visited = vector<bool>(5005, false);
	vector<int>indegree = vector<int>(5005, 0);
	queue<int>q;
	void initialise(vector<vector<int>> &edges) {
		for (vector<int>v:edges) {
			mp[v[0]].push_back(v[1]);
		}
		return;
	}
	void bfs(int n) {
		while (!q.empty()) {
			int x = q.front();
			ans.push_back(x);
			q.pop();
			for (int z:mp[x]) {
				indegree[z]--;
				if (indegree[z] == 0) {
					q.push(z);
				}
			}
		}
		// if i am here it means the queue is now empty
		return;
	}
	void F(int n) {
		for (vector<int>v:mp) {
			for (int x:v) {
				indegree[x]++;
			}
		}
		for (int i = 0; i<n; i++) {
			if (indegree[i] == 0 and !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
		bfs(n);
		return ;
	}
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		initialise(edges);
		F(V);
		return ans;
	}
};
