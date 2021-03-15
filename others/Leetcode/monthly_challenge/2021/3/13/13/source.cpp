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
	int numFactoredBinaryTrees(vector<int>& arr) {
		const int n = arr.size();

		sort(arr.begin(), arr.end());

		vector<long long> val(n);

		long long sol = 1;

		val[0] = 1;

		for (int i = 1; i < n; i++) {
			int ptr = i - 1;
			val[i] = 1;

			for (int j = 0; j < i && arr[j] <= (int)sqrt(arr[i]) && ptr >= j; j++) {
				while (ptr > j && (long long)arr[ptr] * (long long)arr[j] > (long long)arr[i]) {
					ptr--;
				}

				if ((long long)arr[ptr] * (long long)arr[j] == (long long)arr[i]) {
					val[i] = (val[i] + val[j] * val[ptr] % MOD * (1 + (j != ptr)) % MOD) % MOD;
				}
			}

			sol = (sol + val[i]) % MOD;
		}

		return (int)sol;
	}
};

int main()
{

}