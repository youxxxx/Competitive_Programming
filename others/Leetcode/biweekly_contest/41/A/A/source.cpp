#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		const int m = allowed.size();
		int stat[255] = { 0, };

		for (int i = 0; i < m; i++)	{
			stat[allowed[i]] = 1;
		}

		const int n = words.size();

		int sol = 0;

		for (int i = 0; i < n; i++) {
			int add = 1;

			for (int j = 0; j < words[i].size(); j++) {
				if (stat[words[i][j]] == 0) {
					add = 0;

					break;
				}
			}

			sol += add;
		}

		return sol;
	}
};

int main()
{

	return 0;
}