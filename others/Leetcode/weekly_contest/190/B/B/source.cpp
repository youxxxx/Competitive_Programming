#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	int maxVowels(string s, int k) {
		const int n = s.size();
		int val[256] = { 0, };
		int cur = 0;

		val['a'] = val['e'] = val['i'] = val['o'] = val['u'] = 1;

		for (int i = 0; i < k; i++)
		{
			cur += val[s[i]];
		}

		int lmax = cur;

		for (int i = k; i < n; i++)
		{
			cur += val[s[i]] - val[s[i - k]];

			if (cur > lmax)
			{
				lmax = cur;
			}
		}

		return lmax;
	}
};

using namespace std;

int main()
{

	return 0;
}