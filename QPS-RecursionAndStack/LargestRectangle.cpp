class Solution {
public:
	int solve(vector<int>& heights) {
		vector<int> ns(heights.size()), ps(heights.size());
		int n = heights.size();
		stack<int> s;
		ns[n - 1] = n;
		s.push(n - 1);
		for (int i = n - 2; i >= 0; --i)
		{
			int currentHeight = heights[i];
			while (!s.empty() and currentHeight <= heights[s.top()]) {
				s.pop();
			}

			s.empty() ? ns[i] = n : ns[i] = s.top();
			s.push(i);
		}
		while (!s.empty()) s.pop();


		ps[0] = -1;
		s.push(0);
		for (int i = 1; i < n; ++i)
		{
			int currentHeight = heights[i];
			while (!s.empty() and currentHeight <= heights[s.top()]) {
				s.pop();
			}

			s.empty() ? ps[i] = -1 : ps[i] = s.top();
			s.push(i);
		}


		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int width = ns[i] - ps[i] - 1;
			int area = width * heights[i];
			ans = max(ans, area);
		}
		return ans;
	}

	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 1) return heights[0];
		return solve(heights);
	}
};









