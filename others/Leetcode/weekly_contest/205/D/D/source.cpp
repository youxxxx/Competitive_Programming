#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int group1[100001];
	int rank1[100001];
	int group2[100001];
	int rank2[100001];

	int uf1(int a)
	{
		if (a == group1[a])
		{
			return a;
		}

		else return group1[a] = uf1(group1[a]);
	}

	void disj1(int a, int b)
	{
		int next;
		int rvalue;
		int ar, br;

		ar = uf1(a);
		br = uf1(b);

		if (ar == br)
		{
			return;
		}

		if (rank1[ar] <= rank1[br])
		{
			group1[ar] = br;
		}

		else
		{
			group1[br] = ar;
		}

		if (rank1[ar] == rank1[br])
		{
			rank1[ar]++;
		}
	}

	int uf2(int a)
	{
		if (a == group2[a])
		{
			return a;
		}

		else return group2[a] = uf2(group2[a]);
	}

	void disj2(int a, int b)
	{
		int next;
		int rvalue;
		int ar, br;

		ar = uf2(a);
		br = uf2(b);

		if (ar == br)
		{
			return;
		}

		if (rank2[ar] <= rank2[br])
		{
			group2[ar] = br;
		}

		else
		{
			group2[br] = ar;
		}

		if (rank2[ar] == rank2[br])
		{
			rank2[ar]++;
		}
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		for (int i = 1; i <= n; i++) {
			rank1[i] = rank2[i] = 0;
			group1[i] = group2[i] = i;
		}

		vector<pair<int, int>> sep[4];

		for (int i = 0; i < edges.size(); i++) {
			const int u = edges[i][1];
			const int v = edges[i][2];

			switch (edges[i][0]) {
			case 1:
				sep[1].push_back({ u,v });
				break;
			case 2:
				sep[2].push_back({ u,v });
				break;
			case 3:
				sep[3].push_back({ u,v });
				break;
			}
		}

		int sol = 0;

		for (int i = 0; i < sep[3].size(); i++) {
			const int u = sep[3][i].first;
			const int v = sep[3][i].second;

			if (uf1(u) == uf1(v) && uf2(u) == uf2(v)) {
				sol++;
			}

			else {
				if (group1[u] != group1[v]) {
					disj1(u, v);
				}
				
				if (group2[u] != group2[v]) {
					disj2(u, v);
				}
			}
		}

		for (int i = 0; i < sep[1].size(); i++) {
			const int u = sep[1][i].first;
			const int v = sep[1][i].second;

			if (uf1(u) == uf1(v)) {
				sol++;
			}

			else {
				disj1(u, v);
			}
		}

		for (int i = 0; i < sep[2].size(); i++) {
			const int u = sep[2][i].first;
			const int v = sep[2][i].second;

			if (uf2(u) == uf2(v)) {
				sol++;
			}

			else {
				disj2(u, v);
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (uf1(i) != uf1(i+1) || uf2(i) != uf2(i + 1)) {
				return -1;
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	Solution s;
	vector<vector<int>> arr = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};

	s.maxNumEdgesToRemove(4, arr);

	return 0;
}