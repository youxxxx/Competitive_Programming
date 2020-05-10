#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	string reformat(string s) {
		const int n = s.size();
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] >= '0'&&s[i] <= '9')
			{
				cnt++;
			}
		}

		string rvalue;
		string a, b;

		for (int i = 0; i < n; i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				a.push_back(s[i]);
			}

			else
			{
				b.push_back(s[i]);
			}
		}

		if (!(n % 2)) {
			if (cnt != n / 2)
			{
				return rvalue;
			}

			else
			{
				for (int i = 0; i < n / 2; i++)
				{
					rvalue.push_back(a[i]);
					rvalue.push_back(b[i]);
				}
			}

			return rvalue;
		}

		if (!(cnt == n / 2 || cnt == n / 2 + 1))
		{
			return rvalue;
		}

		if (cnt == n / 2)
		{
			for (int i = 0; i < n / 2; i++)
			{
				rvalue.push_back(b[i]);
				rvalue.push_back(a[i]);
			}

			rvalue.push_back(b[n / 2]);

			return rvalue;
		}

		for (int i = 0; i < n / 2; i++)
		{
			rvalue.push_back(a[i]);
			rvalue.push_back(b[i]);
		}

		rvalue.push_back(a[n / 2]);

		return rvalue;
	}
};

int main()
{


	return 0;
}