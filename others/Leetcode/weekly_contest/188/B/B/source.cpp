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
	int countTriplets(vector<int>& arr) {
		const int n = arr.size();

		int cnt = 0;

		for (int i = 0; i < n - 1; i++) {
			int xorval;
			
			xorval = arr[i];

			for (int j = i + 1; j < n; j++) {
				xorval ^= arr[j];

				cnt += !xorval * (j - i);
			}
		}

		return cnt;
	}
};

int main()
{
	return 0;
}