class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int>& a, int s, vector<int> &v) {
		ans.push_back(v);

		if (s == a.size()) {
			return;
		}

		for (int i = s; i < a.size(); ++i)
		{
			if (i != s and a[i] == a[i - 1]) continue;
			v.push_back(a[i]);
			solve(a, i + 1, v);
			v.pop_back();
		}
	}


	vector<vector<int>> subsetsWithDup(vector<int>& a) {
		vector<int> v;
		sort(a.begin(), a.end());
		solve(a, 0, v);
		return ans;
	}
};