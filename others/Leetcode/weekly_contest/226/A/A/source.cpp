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
	int countBalls(int lowLimit, int highLimit) {
		int cnt[101] = { 0, };

		for (int i = lowLimit; i <= highLimit; i++) {
			int temp = i;
			int val = 0;

			while (temp) {
				val += temp % 10;

				temp /= 10;
			}
			
			cnt[val]++;
		}

		int sol = 0;

		for (int i = 1; i <= 100; i++)
		{
			sol = max(sol, cnt[i]);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}