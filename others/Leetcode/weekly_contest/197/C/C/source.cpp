#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		priority_queue<pair<double, int>> pq;

		double sol = 0.0;

		double lmax[10001];

		pq.push({ 1.0,start });

		for (int i = 0; i < n; i++) {
			lmax[i] = 0.0;
		}

		lmax[start] = 1.0;

		const int m = edges.size();

		vector<pair<int, double>> graph[10001];

		for (int i = 0; i < m; i++) {
			graph[edges[i][0]].push_back({ edges[i][1],succProb[i] });
			graph[edges[i][1]].push_back({ edges[i][0],succProb[i] });
		}

		while (!pq.empty()) {
			double prob = pq.top().first;
			int node = pq.top().second;

			pq.pop();

			if (node == end)
			{
				if (prob > sol) {
					sol = prob;
				}

				continue;
			}

			for (int i = 0; i < graph[node].size(); i++) {
				const int next = graph[node][i].first;
				const double mult = graph[node][i].second;

				if (prob*mult > lmax[next]) {
					lmax[next] = prob*mult;

					pq.push({ prob*mult,next });
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