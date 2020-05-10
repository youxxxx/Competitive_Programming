#include<cstdio>
#include<cmath>
#include<string>
#include<vector	
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<stack>
#include<queue>
#include<functional>

#define MOD 1000000007

using namespace std;

class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		vector<pair<int, int>> eng;

		for (int i = 0; i < n; i++) {
			eng.push_back({ efficiency[i],speed[i] });
		}

		sort(eng.begin(), eng.end());

		long long lmax = 0;
		long long sum = 0;
		priority_queue<long long,vector<long long>,greater<long long>> pq;

		for (int i = n - 1; i >= n - k; i--) {
			pq.push((long long)eng[i].second);
			sum += (long long)eng[i].second;

			long long cand;

			cand = sum*eng[i].first;

			if (cand > lmax) {
				lmax = cand;
			}
		}

		for (int i = n - k - 1; i >= 0; i--) {
			pq.push((long long)eng[i].second);
			sum += (long long)eng[i].second;

			sum -= pq.top();
			pq.pop();

			long long cand;

			cand = sum*eng[i].first;

			if (cand > lmax) {
				lmax = cand;
			}
		}

		return lmax%MOD;
	}
};

int main()
{
	vector<int> s = { 2,8,2 }, e = { 2,7,1 };

	Solution sol;
	sol.maxPerformance(3, s, e, 2);
}