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
	int totalMoney(int n) {
		int sol = 0;

		for (int i = 0; i < n / 7; i++)	{
			sol += 28 + i * 7;
		}

		for (int i = 0; i < n % 7; i++)	{
			sol += n / 7 + i + 1;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}