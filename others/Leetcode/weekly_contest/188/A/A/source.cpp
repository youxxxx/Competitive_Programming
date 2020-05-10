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
	vector<string> buildArray(vector<int>& target, int n) {
		int ptr = 0;
		vector<string> sol;
		const int m = target.size();

		for (int i = 1; i <= n; i++) {
			if (ptr == m) {
				break;
			}

			if (target[ptr] != i) {
				sol.push_back("Push");
				sol.push_back("Pop");
			}

			else {
				sol.push_back("Push");
				ptr++;
			}
		}
		
		return sol;
	}
};

int main()
{
	return 0;
}