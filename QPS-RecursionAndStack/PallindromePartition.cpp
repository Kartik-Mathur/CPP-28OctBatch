class Solution {
public:
	vector<vector<string>> ans;

	bool isPalindrome(string &x) {
		int i = 0, j = x.size() - 1;
		while (i < j) {
			if (x[i++] != x[j--]) return false;
		}
		return true;
	}

	void solve(string &s, vector<string> &v, int si = 0) {
		// base case
		if (si == s.size()) {
			ans.push_back(v);
			return;
		}

		// recursive case
		for (int i = si; i < s.size(); ++i)
		{
			string x = s.substr(si, i - si + 1);
			if (isPalindrome(x)) {
				v.push_back(x);
				solve(s, v, i + 1);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<string> v;
		solve(s, v);
		return ans;

	}
};