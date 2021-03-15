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
	bool areAlmostEqual(string s1, string s2) {
		const int n = s1.size();

		int diff = 0;

		for (int i = 0; i < n; i++)	{
			diff += (s1[i] != s2[i]);
		}

		if (diff != 0 && diff != 2) {
			return false;
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{

}