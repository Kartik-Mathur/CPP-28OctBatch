class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int>& a, int target, int i, int sum, vector<int>&v) {
		if (i == a.size()) return;
		if (target == sum) {
			ans.push_back(v);
			return;
		}

		if (sum + a[i] <= target) {
			v.push_back(a[i]);
			solve(a, target, i, sum + a[i], v);
			v.pop_back();
		}
		solve(a, target, i + 1, sum, v);
	}

	vector<vector<int>> combinationSum(vector<int>& a, int target) {
		vector<int> v;
		solve(a, target, 0, 0, v);
		return ans;
	}
};