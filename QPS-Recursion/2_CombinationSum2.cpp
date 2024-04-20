class Solution {
public:
	vector<vector<int>> ans;
	void solve(vector<int>& a, int target, int s, int sum, vector<int>&v) {
		if (target == sum) {
			ans.push_back(v);
			return;
		}

		if (s == a.size()) return;

		for (int i = s; i < a.size(); ++i)
		{
			if (i != s and a[i] == a[i - 1]) continue;
			if (sum + a[i] > target) break;
			v.push_back(a[i]);
			solve(a, target, i + 1, sum + a[i], v);
			v.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& a, int target) {
		vector<int> v;
		sort(a.begin(), a.end());
		solve(a, target, 0, 0, v);
		return ans;
	}
};