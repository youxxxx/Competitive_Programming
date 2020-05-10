#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int numTeams(vector<int>& rating) {
		int n;

		n = rating.size();

		int sol = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					sol += (rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k]);
				}
			}
		}

		return sol;
	}
};

int main()
{

	return 0;
}