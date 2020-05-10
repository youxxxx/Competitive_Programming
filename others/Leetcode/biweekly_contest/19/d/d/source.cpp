#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
	int minJumps(vector<int>& arr) {
		int n;
		int lmin[50001];

		memset(lmin, -1, sizeof(lmin));

		n = arr.size();

		map<int, vector<int>> dlist;

		for (int i = 0; i < n; i++) {
			map<int, vector<int>>::iterator ret;
			ret = dlist.find(arr[i]);

			if (ret == dlist.end()) {
				vector<int> newvec;

				newvec.push_back(i);

				dlist[arr[i]] = newvec;
			}

			else {
				ret->second.push_back(i);
			}
		}

		queue<pair<int, int>> q;
		set<int> visited;

		q.push({ 0, 0 });

		while (!q.empty()) {
			int idx;
			int cnt;

			idx = q.front().first;
			cnt = q.front().second;
			q.pop();

			if (idx == n - 1) {
				return cnt;
			}

			map<int, vector<int>>::iterator ret;
			set<int>::iterator ret2;

			ret2 = visited.find(arr[idx]);

			if (ret2 == visited.end()) {
				visited.insert(arr[idx]);

				ret = dlist.find(arr[idx]);

				for (int i = 0; i < ret->second.size(); i++) {
					lmin[ret->second[i]] = cnt + 1;

					q.push({ ret->second[i], cnt + 1 });
				}
			}

			if (idx > 0 && lmin[idx - 1] == -1)
			{
				lmin[idx - 1] = cnt + 1;

				q.push({ idx - 1, cnt + 1 });
			}

			if (idx < n - 1 && lmin[idx + 1] == -1)
			{
				lmin[idx + 1] = cnt + 1;

				q.push({ idx + 1, cnt + 1 });
			}
		}

		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 7,6,9,6,9,6,9,7 };

	s.minJumps(arr);

	return 0;
}