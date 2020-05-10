#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string sortString(string s) {
		string sol;

		int cnt[26] = { 0, };
		int n;

		n = s.size();

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		int left;

		left = n;

		while (left)
		{
			for (int i = 0; i < 26; i++) {
				if (cnt[i]) {
					cnt[i]--;

					sol.push_back(i + 'a');

					left--;
				}

				if (!left)
				{
					break;
				}
			}

			if (!left)
			{
				break;
			}

			for (int i = 25; i >= 0; i--) {
				if (cnt[i]) {
					cnt[i]--;

					sol.push_back(i + 'a');

					left--;
				}

				if (!left)
				{
					break;
				}
			}

			if (!left)
			{
				break;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
}