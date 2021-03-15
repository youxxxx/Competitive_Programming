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
	bool hasAllCodes(string s, int k) {
		const int n = s.size();
		int arr[1 << 20];

		if (n < k) {
			return false;
		}

		fill(&arr[0], &arr[1 << k], 0);

		int cur = 0;

		int cnt = 0;

		for (int i = 0; i < k - 1; i++) {
			cur = (cur << 1) % (1 << k) + (s[i] - '0');
		}

		for (int i = k - 1; i < n; i++) {
			cur = (cur << 1) % (1 << k) + (s[i] - '0');

			cnt += !arr[cur];

			arr[cur] = true;
		}

		return cnt == (1 << k);
	}
};

int main()
{

}