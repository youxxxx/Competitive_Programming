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
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();

		if (!amount) {
			return 0;
		}

		for (int j = n - 1; j >= 0; j--) {
			if (coins[j] > amount) {
				coins.erase(coins.begin() + j);

				n--;
			}
		}

		map<int, int> list;

		priority_queue<pair<int, int>> pq;

		pq.push({ 0,0 });

		while (!pq.empty()) {
			const int cur = pq.top().second;
			const int cnt = -pq.top().first;
			pq.pop();

			if (cur == amount) {
				return cnt;
			}

			if (list[cur] != cnt) {
				continue;
			}

			for (int i = 0; i < n; i++) {
				const int next = cur + coins[i];
				
				if (next <= amount) {
					const map<int, int>::iterator it = list.find(next);

					if (it == list.end()) {
						list[next] = cnt + 1;

						pq.push({ -(cnt + 1),next });
					}

					else {
						if (cnt + 1 < it->second) {
							pq.push({ -(cnt + 1),next });

							it->second = cnt + 1;
						}
					}
				}
			}
		}

		return -1;
	}
};

int main()
{

}