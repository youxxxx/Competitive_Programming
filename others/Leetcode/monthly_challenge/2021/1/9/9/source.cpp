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
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		const int n = wordList.size();
		const int m = beginWord.size();

		int e = -1;

		for (int i = 0; i < n; i++)	{
			if (wordList[i] == endWord) {
				e = i;
			}
		}

		if (e == -1) {
			return 0;
		}

		vector<int> graph[5001];

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int cnt = 0;

				for (int k = 0; k < m && cnt != 2; k++) {
					if (wordList[i][k] != wordList[j][k]) {
						cnt++;
					}
				}

				if (cnt == 1) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int cnt = 0;

			for (int k = 0; k < m && cnt != 2; k++) {
				if (beginWord[k] != wordList[i][k]) {
					cnt++;
				}
			}

			if (cnt == 1) {
				graph[5000].push_back(i);
			}
		}

		int dist[5001];

		memset(dist, -1, sizeof(dist));

		dist[5000] = 0;

		queue<int> q;

		q.push(5000);
		
		while (!q.empty()) {
			const int cur = q.front();
			q.pop();

			if (cur == e) {
				break;
			}

			for (int i = 0; i < (int)graph[cur].size(); i++) {
				const int next = graph[cur][i];

				if (dist[next] == -1) {
					dist[next] = dist[cur] + 1;

					q.push(next);
				}
			}
		}

		return dist[e] + 1;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}