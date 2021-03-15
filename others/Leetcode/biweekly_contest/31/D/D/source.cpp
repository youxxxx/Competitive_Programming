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
	int minNumberOperations(vector<int>& target) {
		const int n = target.size();

		vector<pair<int, int>> arr;

		for (int i = 0; i < n; i++) {
			arr.push_back({ target[i],i });
		}

		sort(arr.begin(), arr.end());

		int sol = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i].second == 0) {
				sol+=arr[i].first;
			}

			else if (target[arr[i].second - 1] < arr[i].first) {
				sol += arr[i].first - target[arr[i].second - 1];
			}
		}

		return sol;
	}
};

int main()
{

	return 0;
} 