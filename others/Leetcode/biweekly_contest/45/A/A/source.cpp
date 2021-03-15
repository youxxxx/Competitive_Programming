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
	int sumOfUnique(vector<int>& nums) {
		const int n = nums.size();
		
		int cnt[101] = { 0, };

		for (int i = 0; i < n; i++)	{
			cnt[nums[i]]++;
		}

		int sol = 0;

		for (int i = 1; i <= 100; i++) {
			if (cnt[i] == 1) {
				sol += i;
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}