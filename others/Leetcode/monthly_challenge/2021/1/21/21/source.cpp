#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define N 100000
#define MAX 1000000000

class Solution {
public:
	int mintree[N * 4];

	int setmin(int idx, int val, int cur, int l, int r)
	{
		if (l == r)
		{
			return mintree[cur] = val;
		}

		const int mid = (l + r) / 2;

		int ret;

		if (idx <= mid)
		{
			ret = setmin(idx, val, cur * 2, l, mid);
		}

		else
		{
			ret = setmin(idx, val, cur * 2 + 1, mid + 1, r);
		}

		if (ret < mintree[cur])
		{
			mintree[cur] = ret;
		}

		return mintree[cur];
	}

	int getmin(int lb, int ub, int cur, int l, int r)
	{
		if (l == r)
		{
			return mintree[cur];
		}

		if (l > ub || r < lb)
		{
			return 0;
		}

		if (l >= lb && r <= ub)
		{
			return mintree[cur];
		}

		const int mid = (l + r) / 2;

		if (ub <= mid)
		{
			return getmin(lb, ub, cur * 2, l, mid);
		}

		if (lb >= mid + 1)
		{
			return getmin(lb, ub, cur * 2 + 1, mid + 1, r);
		}

		const int left = getmin(lb, ub, cur * 2, l, mid);
		const int right = getmin(lb, ub, cur * 2 + 1, mid + 1, r);


		return left < right ? left : right;
	}

	vector<int> mostCompetitive(vector<int>& nums, int k) {
		const int n = nums.size();

		for (int i = 0; i < n * 4; i++) {
			mintree[i] = MAX;
		}

		for (int i = 0; i < n; i++) {
			setmin(i + 1, nums[i], 1, 1, n);
		}

		int ptr = n - k;
		
		vector<int> sol;

		for (int i = 0; i < n && ptr < n; i++) {
			if (getmin(i + 1, ptr + 1, 1, 1, n) == nums[i]) {
				sol.push_back(nums[i]);

				ptr++;
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}