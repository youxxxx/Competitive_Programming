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
	int numRescueBoats(vector<int>& people, int limit) {
		const int n = people.size();

		sort(people.begin(), people.end());

		int ptr = n - 1;

		int sol = 0;

		for (int i = 0; i < n && ptr >= i; i++) {
			while (ptr > i&&people[ptr] + people[i] > limit) {
				sol++;

				ptr--;
			}

			sol++;

			ptr--;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}