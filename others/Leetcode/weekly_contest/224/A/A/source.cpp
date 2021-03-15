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
	int countGoodRectangles(vector<vector<int>>& rectangles) {
		const int n = rectangles.size();

		int lmax = 0;

		for (int i = 0; i < n; i++) {
			lmax = max(lmax, min(rectangles[i][0], rectangles[i][1]));
		}

		int sol = 0;

		for (int i = 0; i < n; i++) {
			sol += (min(rectangles[i][0], rectangles[i][1]) >= lmax);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}