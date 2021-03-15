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
	int minimumOneBitOperations(int n) {
		if (!n) {
			return 0;
		}

		vector<int> bits;
		int temp = n;
		int val[31];

		val[0] = 1;

		for (int i = 1; i <= 30; i++)
		{
			val[i] = val[i - 1] * 2 + 1;
		}

		int cnt = 0;

		while (temp)
		{
			if (temp % 2) {
				bits.push_back(cnt);
			}

			temp /= 2;
			cnt++;
		}
		
		int sol = 0;
		int sign = 1;

		for (int i = bits.size() - 1; i >= 0; i--)
		{
			sol += val[bits[i]] * sign;
			sign *= -1;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	s.minimumOneBitOperations(7);

	return 0;
}