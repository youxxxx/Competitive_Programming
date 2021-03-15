#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		const int n = target.size();

		sort(target.begin(), target.end());
		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; i++) {
			if (target[i] != arr[i]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{

	return 0;
}