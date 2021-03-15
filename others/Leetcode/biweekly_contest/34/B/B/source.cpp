#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

class Solution {
public:
	int numWays(string s) {
		const int n = s.size();
		int tot = 0;

		for (int i = 0; i < n; i++) {
			tot += s[i] - '0';
		}

		if (tot % 3) {
			return 0;
		}

		if (tot == 0) {
			return (long long)(n - 1)*(long long)(n - 2) / 2 % MOD;
		}

		int cnt = 0;

		long long a = 0, b = 0;

		for (int i = 0; i < n; i++) {
			cnt += s[i] - '0';

			if (cnt == tot / 3) {
				a++;
			}

			else if (cnt == tot / 3 * 2) {
				b++;
			}
		}

		return (a*b) % MOD;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);


	return 0;
}