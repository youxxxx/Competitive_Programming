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
	int beautySum(string s) {
		const int n = s.size();

		int psum[26][501];

		for (int i = 0; i < 26; i++)
		{
			psum[i][0] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				psum[j][i] = psum[j][i - 1] + (s[i - 1] == j + 'a');
			}
		}

		int sol = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				int lmin = 500;
				int lmax = 0;

				for (int k = 0; k < 26; k++) {
					if (psum[k][i] - psum[k][j]) {
						lmin = min(lmin, psum[k][i] - psum[k][j]);
						lmax = max(lmax, psum[k][i] - psum[k][j]);
					}
				}

				sol += lmax - lmin;
			}
		}

		return sol;
	}
};

int main()
{

}