#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

		int n;
		vector<int> cur[501];
		vector<vector<int>> sol;
		int cnt[501] = { 0, };

		n = groupSizes.size();

		for (int i = 0; i < n; i++)
		{
			cur[groupSizes[i]].push_back(i);

			if (++cnt[groupSizes[i]] == groupSizes[i])
			{
				sol.push_back(cur[groupSizes[i]]);
				cur[groupSizes[i]].clear();
				cnt[groupSizes[i]] = 0;
			}
		}

		return sol;
	}
};

int main()
{


	return 0;
}