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

class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		bool all[2] = { 1,1 };

		const int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			all[!nums[i]] = false;
		}

		if (all[0])
		{
			return 0;
		}

		if (all[1])
		{
			return n - 1;
		}

		vector<pair<int,pair<int,int>>> arr;
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (nums[i])
			{
				cnt++;
			}

			else
			{
				if (cnt)
				{
					arr.push_back({ cnt,{ i - cnt,i - 1 } });
				}

				cnt = 0;
			}
		}

		if (cnt)
		{
			arr.push_back({ cnt,{ n - cnt, n - 1} });
		}

		cnt = 0;

		if (arr.size() == 1)
		{
			return arr[0].first;
		}

		int sol = 0;

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].first > sol)
			{
				sol = arr[i].first;
			}
		}

		for (int i = 0; i < arr.size() - 1; i++)
		{
			if (arr[i].second.second == arr[i + 1].second.first - 2 && arr[i].first + arr[i + 1].first > sol)
			{
				sol = arr[i].first + arr[i + 1].first;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 0, 1, 1, 1, 0, 1, 1, 0, 1 };

	s.longestSubarray(arr);

	return 0;
}