#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		int n;

		n = arr.size();

		int curmax = -1;

		vector<int> sol(n);

		for (int i = n - 1; i >= 0; i--) {
			sol[i] = curmax;

			if (arr[i] > curmax) {
				curmax = arr[i];
			}
		}

		return sol;
	}
};

int main()
{


	return 0;
}