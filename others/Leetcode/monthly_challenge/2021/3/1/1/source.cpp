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
	int distributeCandies(vector<int>& candyType) {
		const int n = candyType.size();
		set<int> list;

		for (int i = 0; i < n; i++) {
			list.insert(candyType[i]);
		}

		return min((int)list.size(), n / 2);
	}
};

int main()
{

}