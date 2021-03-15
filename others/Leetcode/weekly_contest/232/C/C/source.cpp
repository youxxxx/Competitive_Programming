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

class comp {
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
		return (double)a.first / (double)a.second - (double)a.first / (double)(a.second + 1)
			< (double)b.first / (double)b.second - (double)b.first / (double)(b.second + 1);
	}
};

class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		const int n = classes.size();

		priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

		double cur = 0.0;

		for (int i = 0; i < n; i++) {
			cur += (double)(classes[i][1] - classes[i][0]) / (double)classes[i][1];

			pq.push({ (classes[i][1] - classes[i][0]) ,classes[i][1] });
		}

		for (int i = 0; i < extraStudents; i++) {
			const int pass = pq.top().first;
			const int tot = pq.top().second;
			pq.pop();

			cur += (double)pass / (double)(tot + 1) - (double)pass / (double)tot;

			pq.push({ pass,tot + 1 });
		}

		return 1.0 - (cur / (double)n);
	}
};

int main()
{

}