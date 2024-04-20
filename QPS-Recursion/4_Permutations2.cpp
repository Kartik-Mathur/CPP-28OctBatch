class Solution {
public:
	vector<vector<int>> ans;

	void solve(vector<int>& a, int s) {
		if (s == a.size()) {
			ans.push_back(a);
			return;
		}

		int freq[21] = {0};
		for (int i = s; i < a.size(); ++i)
		{
			if (freq[a[i] + 10] > 0) continue;
			freq[a[i] + 10]++;
			swap(a[i], a[s]);
			solve(a, s + 1);
			swap(a[i], a[s]);
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& a) {
		// sort(a.begin(), a.end());
		solve(a, 0);
		return ans;
	}
};