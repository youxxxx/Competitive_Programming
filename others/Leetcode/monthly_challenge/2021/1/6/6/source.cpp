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
	int findKthPositive(vector<int>& arr, int k) {
		const int n = arr.size();
		int lb = -1, ub = n;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2) {
			if (arr[next] <= k + next) {
				lb = next;
			}

			else {
				ub = next;
			}
		}

		return k + ub;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}