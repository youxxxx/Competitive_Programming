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
	int findCenter(vector<vector<int>>& edges) {
		const int n = edges.size();
		int cnt[100001];
		fill(&cnt[1], &cnt[n + 2], 0);

		for (int i = 0; i < n; i++) {
			if (cnt[edges[i][0]]++) {
				return edges[i][0];
			}

			if (cnt[edges[i][1]]++) {
				return edges[i][1];
			}
		}

		return -1;
	}
};

int main()
{

}