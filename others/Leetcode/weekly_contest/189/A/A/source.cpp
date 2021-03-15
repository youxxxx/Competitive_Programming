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
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		const int n = startTime.size();
		int sol = 0;

		for (int i = 0; i < n; i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				sol++;
			}
		}

		return sol;
	}
};

int main()
{

	return 0;
}