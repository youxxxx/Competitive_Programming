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

class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		const int n = arr.size();
		const int m = pieces.size();

		int ptr = 0;

		int loc[101];

		memset(loc, -1, sizeof(loc));

		for (int i = 0; i < m; i++) {
			loc[pieces[i][0]] = i;
		}

		while (ptr != n) {
			if (loc[arr[ptr]] == -1) {
				break;
			}

			bool valid = true;

			for (int j = 0; j < (int)pieces[loc[arr[ptr]]].size(); j++) {
				if (arr[ptr + j] != pieces[loc[arr[ptr]]][j]) {
					valid = false;

					break;
				}
			}

			if (!valid) {
				break;
			}

			ptr += (int)pieces[loc[arr[ptr]]].size();
		}

		return (ptr == n);
	}
};

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}