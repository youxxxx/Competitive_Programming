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
	bool isPathCrossing(string path) {
		int dx[256] = { 0, };
		int dy[256] = { 0, };

		dx['N'] = 1;
		dx['S'] = -1;
		dy['E'] = 1;
		dy['W'] = -1;

		const int n = path.size();

		set<int> coord[20001];

		coord[10000].insert(10000);

		int x = 10000, y = 10000;

		for (int i = 0; i < n; i++) {
			x += dx[path[i]];
			y += dy[path[i]];

			set<int>::iterator ret;

			ret = coord[x].find(y);

			if (ret != coord[x].end()) {
				return true;
			}

			coord[x].insert(y);
		}

		return false;
	}
};

int main()
{
	Solution s;

	s.isPathCrossing("NES");

	return 0;
}