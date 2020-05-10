#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
	vector<int> graph[101];
	bool visited[101];
	vector<int> sol;
	map<string, int> list;

	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		int n;

		n = watchedVideos.size();

		queue<pair<int,int>> q;

		for (int i = 0; i <= n; i++) {
			visited[i] = false;
		}
		
		visited[id] = true;

		q.push({ id,0 });

		vector<int> target;

		while (!q.empty()) {
			int node, cnt;

			node = q.front().first;
			cnt = q.front().second;
			q.pop();

			if (cnt == level) {
				target.push_back(node);
			}

			for (int i = 0; i < friends[node].size(); i++) {
				int next;

				next = friends[node][i];

				if (!visited[next])	{
					visited[next] = true;

					q.push({ next,cnt + 1 });
				}
			}
		}

		for (int i = 0; i < target.size(); i++) {
			map<string, int>::iterator ret;

			for (int j = 0; j < watchedVideos[target[i]].size(); j++) {
				string video;

				video = watchedVideos[target[i]][j];

				ret = list.find(video);

				if (ret == list.end()) {
					list[video] = 1;
				}

				else {
					ret->second++;
				}
			}
		}

		map<string, int>::iterator it;

		vector<pair<int, string>> sorted;

		for (it = list.begin(); it != list.end(); it++) {
			sorted.push_back({ it->second,it->first });
		}

		sort(sorted.begin(), sorted.end());

		vector<string> rvalue;

		for (int i = 0; i < sorted.size(); i++) {
			rvalue.push_back(sorted[i].second);
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	return 0;
}