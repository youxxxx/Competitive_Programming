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

class Solution{

public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		const int n = mat.size();
		const int m = mat[0].size();

		vector<pair<int,int>> arr;

		for (int i = 0; i < n; i++) {
			int sum = 0;

			for (int j = 0; j < m; j++) {
				sum += mat[i][j];
			}

			arr.push_back({ sum,i });
		}

		sort(arr.begin(), arr.end());

		vector<int> sol;

		for (int i = 0; i < k; i++) {
			sol.push_back(arr[i].second);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}