class Solution {
public:
	static bool mycompare(vector<int> &a, vector<int> &b) {
		if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}


	int minMeetingRooms(vector<vector<int>>& v) {
		sort(v.begin(), v.end(), mycompare);
		// Minheap
		priority_queue<int, vector<int>, greater<int> > q;

		for (int i = 0; i < v.size(); ++i)
		{
			if (q.empty()) {
				q.push(v[i][1]);
			}
			else {
				if (!q.empty() and
				        v[i][0] >= q.top()) {
					q.pop();
				}

				q.push(v[i][1]);
			}
		}

		return q.size();
	}
};















