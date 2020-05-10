#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool func(vector<int> &a, vector<int> &b){
	return a.front() < b.front() || a.front() == b.front() && a.back() > b.back();
}

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int cnt = 0;
		int n;
		int lmax = 0;

		n = intervals.size();

		sort(intervals.begin(), intervals.end(), func);

		for (int i = 0; i < n; i++) {
			if (intervals[i].back() > lmax) {
				lmax = intervals[i].back();
			}

			else {
				cnt++;
			}
		}

		return n - cnt;
	}
};

int main()
{
	return 0;
}