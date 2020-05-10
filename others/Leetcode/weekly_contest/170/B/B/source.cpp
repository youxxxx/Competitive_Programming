#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> acc;

		acc.push_back(0);

		int cur = 0;

		int n, m;

		n = arr.size();
		m = queries.size();

		for (int i = 0; i < n; i++)	{
			cur ^= arr[i];
			acc.push_back(cur);
		}

		vector<int> rvalue;

		for (int i = 0; i < m; i++) {
			rvalue.push_back(acc[queries[i][1] + 1] ^ acc[queries[i][0]]);
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	return 0;
}