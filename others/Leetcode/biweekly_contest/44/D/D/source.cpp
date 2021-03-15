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
	long long perm[20001];

	long long exp(long long base, long long pw) {
		long long rvalue = 1;

		while (pw) {
			if (pw % 2) {
				rvalue = rvalue*base%MOD;
			}

			base = base*base%MOD;

			pw /= 2;
		}

		return rvalue;
	}

	long long div(long long base) {
		return exp(base, MOD - 2);
	}

	long long ncr(long long n, long long r) {
		return perm[n] * div(perm[r]) % MOD * div(perm[n - r]) % MOD;
	}

	long long nhr(long long n, long long r) {
		return perm[n + r - 1] * div(perm[r]) % MOD * div(perm[n - 1]) % MOD;;
	}

	vector<int> waysToFillArray(vector<vector<int>>& queries) {

		perm[0] = perm[1] = 1;

		for (long long i = 2; i <= 20000; i++) {
			perm[i] = perm[i - 1] * i%MOD;
		}

		vector<int> prime = { 2, };

		for (int i = 3; i < 100; i += 2) {
			bool isprime = true;

			for (int j = 0; j < (int)prime.size() && prime[j] * prime[j] <= i; j++) {
				if (!(i%prime[j])) {
					isprime = false;

					break;
				}
			}

			if (isprime) {
				prime.push_back(i);
			}
		}

		vector<int> sol;

		vector<long long> fac;

		for (int i = 0; i < (int)queries.size(); i++) {
			const int n = queries[i][0];
			const int m = queries[i][1];

			fac.clear();
			int temp = m;

			for (int j = 0; j < (int)prime.size(); j++) {
				if (!(temp%prime[j])) {
					long long cnt = 0;

					while (!(temp%prime[j])) {
						temp /= prime[j];

						cnt++;
					}

					fac.push_back(cnt);
				}
			}
			
			if (temp != 1) {
				fac.push_back(1);
			}

			long long val = 1;

			for (int j = 0; j < (int)fac.size(); j++) {
				val = val*(nhr((long long)(fac[j] + 1), (long long)(n - 1))) % MOD;
			}

			sol.push_back((int)val);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	vector<vector<int>> arr = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 } };

	s.waysToFillArray(arr);

	return 0;
}