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

bool func(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first > b.first;
}

class Solution {
public:

	int maxArea(vector<int>& height) {
		const int n = height.size();

		pair<int, int> arr[30001];

		for (int i = 0; i < n; i++)	{
			arr[i] = { height[i],i };
		}

		sort(&arr[0], &arr[n], func);

		int lmin = arr[0].second;
		int lmax = arr[0].second;

		int sol = 0;

		for (int i = 0; i < n; i++) {
			sol = max(sol, arr[i].first*max(abs(arr[i].second - lmin), abs(arr[i].second - lmax)));

			lmin = min(lmin, arr[i].second);
			lmax = max(lmax, arr[i].second);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}