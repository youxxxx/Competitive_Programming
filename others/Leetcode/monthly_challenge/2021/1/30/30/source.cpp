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

class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		const int n = nums.size();

		priority_queue<pair<int,int>> pq;

		vector<pair<int, int>> arr;

		for (int i = 0; i < n; i++) {
			pair<int, int> cur = { nums[i],-nums[i] };

			while (!(cur.first % 2)) {
				cur.first /= 2;
			}

			if (cur.second % 2)
			{
				cur.second *= 2;
			}

			arr.push_back(cur);
		}

		sort(arr.begin(),arr.end());

		int sol = arr.back().first - arr.front().first;

		int ptr;

		for (ptr = 0; ptr < (int)arr.size() && arr[ptr].first != -arr[ptr].second; ptr++) {
			arr.insert(lower_bound(arr.begin() + ptr, arr.end(), pair<int,int>(arr[ptr].first*2,arr[ptr].second)), { arr[ptr].first * 2,arr[ptr].second });

			sol = min(sol, max(arr[ptr].first * 2,arr.back().first) - arr[ptr + 1].first);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}