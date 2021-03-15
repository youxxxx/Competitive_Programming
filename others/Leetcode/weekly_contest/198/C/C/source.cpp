#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

bool func(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
	return a.first.second < b.first.second;
}
class Solution {
public:
	vector<string> sol;

	bool dfs(string s) {
		const int n = s.size();
		int lmin[26], lmax[26] = { 0, };
		int cnt[26] = { 0, };

		memset(lmin, -1, sizeof(lmin));

		for (int i = 0; i < n; i++) {
			const int ch = s[i] - 'a';

			if (lmin[ch] == -1) {
				lmin[ch] = i;
			}

			lmax[ch] = i;

			cnt[ch]++;
		}

		vector<pair<pair<int, int>, int>> arr;

		int curmin = -1, curmax = -1;
		int curcnt = 0;

		for (int i = 0; i < 26; i++) {
			if (lmin[i] != -1) {
				arr.push_back({ { lmin[i],lmax[i] },i });
			}
		}

		sort(arr.begin(), arr.end(), func);

		bool fcall = false;

		for (int i = 0; i < arr.size(); i++) {
			if (curmin == -1 || arr[i].first.first > curmax) {
				curmin = arr[i].first.first;
				curmax = arr[i].first.second;
				curcnt = cnt[arr[i].second];
			}

			else if (arr[i].first.first > curmin) {
					curmax = arr[i].first.second;

					curcnt += cnt[arr[i].second];
				}

			if (curmax - curmin + 1 == curcnt && (curmin != 0 || curmax != n - 1)) {
				dfs(s.substr(curmin, curmax - curmin + 1));

				curmin = -1;
				curcnt = 0;

				fcall = true;
			}
		}

		if (!fcall) {
			sol.push_back(s);
		}

		return fcall;
	}

	vector<string> maxNumOfSubstrings(string s) {
		dfs(s);

		return sol;
	}
};

int main()
{
	Solution s;
	string str = "cacacb";

	s.maxNumOfSubstrings(str);

	return 0;
}