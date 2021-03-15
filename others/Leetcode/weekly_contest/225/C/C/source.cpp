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
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		const int n = matrix.size();
		const int m = matrix[0].size();

		int acc[2][1001];

		acc[0][0] = matrix[0][0];

		vector<int> arr;

		arr.push_back(acc[0][0]);

		for (int i = 1; i < m; i++) {
			acc[0][i] = acc[0][i - 1] ^ matrix[0][i];

			arr.push_back(acc[0][i]);
		}

		for (int i = 1; i < n; i++) {
			acc[i % 2][0] = acc[!(i % 2)][0] ^ matrix[i][0];

			arr.push_back(acc[i%2][0]);

			int lacc = matrix[i][0];

			for (int j = 1; j < m; j++) {
				lacc ^= matrix[i][j];

				acc[i % 2][j] = lacc ^ acc[!(i % 2)][j];

				arr.push_back(acc[i % 2][j]);
			}
		}

		sort(arr.begin(), arr.end(), greater<int>());

		return arr[k - 1];
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}