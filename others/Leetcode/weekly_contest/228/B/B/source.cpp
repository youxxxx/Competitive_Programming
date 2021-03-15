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
	int countHomogenous(string s) {
		const int n = s.size();
		long long val[100001];

		val[1] = 1;

		for (int i = 2; i <= n; i++) {
			val[i] = (val[i - 1] + i) % MOD;
		}

		long long sol = 0;
		int cnt = 1;
		char cur = s[0];

		for (int i = 1; i < n; i++)
		{
			if (s[i] != cur) {
				sol = (sol + val[cnt]) % MOD;

				cur = s[i];
				cnt = 1;
			}

			else {
				cnt++;
			}
		}

		sol = (sol + val[cnt]) % MOD;

		return (int)sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}