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

#define MOD 1000000007

class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		const int n = nums.size();

		long long lb = 0;
		long long ub = 1000000000;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2) {
			long long cnt = 0;

			for (int i = 0; i < n; i++) {
				cnt += max(0, ((nums[i] + next - 1) / next) - 1);

				if (cnt > (long long)maxOperations) {
					break;
				}
			}

			if (cnt > (long long)maxOperations) {
				lb = next;
			}

			else {
				ub = next;
			}
		}
		
		return (int)ub;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}