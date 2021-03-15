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
	int getMaximumGenerated(int n) {
		int arr[102];

		arr[0] = 0;
		arr[1] = 1;

		int sol = !!n;

		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i / 2] + arr[i / 2 + 1] * (i % 2);

			sol = max(sol, arr[i]);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}