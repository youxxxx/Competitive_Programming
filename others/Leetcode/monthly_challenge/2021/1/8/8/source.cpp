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
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		int i = 0;
		int j = 0;
		const int n = word1.size();
		const int m = word2.size();
		int ptr1 = 0, ptr2 = 0;

		while (i != n) {
			if (j == m) {
				return false;
			}

			if (word1[i][ptr1] != word2[j][ptr2]) {
				return false;
			}

			if (++ptr1 == (int)word1[i].size()) {
				i++;
				ptr1 = 0;
			}

			if (++ptr2 == (int)word2[j].size()) {
				j++;
				ptr2 = 0;
			}
		}

		if (j != m) {
			return false;
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}