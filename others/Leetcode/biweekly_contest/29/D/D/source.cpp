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

class Solution {
public:
	int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
		int in[16] = { 0, };
		vector<int> out[16], rev[16];
		int dep[16][16] = { 0 };

		const int m = dependencies.size();

		for (int i = 0; i < m; i++)
		{
			const int u = dependencies[i][0];
			const int v = dependencies[i][1];

			in[v]++;
			out[u].push_back(v);
			rev[v].push_back(u);
			dep[u][v] = 1;
		}

		queue<int> q;

		vector<int> term;

		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				if (out[i].empty())
				{
					term.push_back(i);
				}

				else
				{
					q.push(i);
				}
		 	}
		}
		int sol = 1;
		int cnt = 0;
		int label[15] = { 0, };
		vector<int> list;
		int left = n;

		while (!q.empty())
		{
			const int cur = q.front();
			q.pop();

			for (int i = 0; i < out[cur].size(); i++)
			{
				const int next = out[cur][i];

				label[next] = label[cur] + 1;

				if (!(--in[next]))
				{
					if (out[next].empty())
					{
						term.push_back(next);
					}

					else
					{
						q.push(next);
					}
				}
			}

			if (cnt == k)
			{
				list.clear();

				sol++;

				cnt = 1;
			}

			else
			{
				bool prev = false;

				for (int i = 0; i < list.size(); i++)
				{
					if (dep[list[i]][cur])
					{
						prev = true;

						break;
					}
				}

				if (prev)
				{
					list.clear();

					for (int i = term.size() - 1; i >= 0 && cnt < k; i--)
					{
						bool valid = true;

						for (int j = 0; j < list.size(); j++)
						{
							if (dep[list[j]][term[i]])
							{
								valid = false;

								break;
							}
						}

						if (dep[cur][term[i]])
						{
							valid = false;
						}

						if (valid)
						{
							term.pop_back();

							cnt++;
						}
					}

					sol++;

					cnt -= k;
				}

				else
				{
					cnt++;
				}
			}

			list.push_back(cur);
		}

		if (cnt == k)
		{
			list.clear();

			cnt = 0;

			if (!term.empty())
			{
				sol++;
			}
		}

		for (int i = term.size() - 1; i >= 0 && cnt < k; i--)
		{
			bool valid = true;

			for (int j = 0; j < list.size(); j++)
			{
				if (dep[list[j]][term[i]])
				{
					valid = false;

					break;
				}
			}

			if (valid)
			{
				term.pop_back();

				if (++cnt == k + 1)
				{
					cnt = 1;

					sol++;

					break;
				}
			}
		}

		if (!term.empty())
		{
			if (cnt)
			{
				sol++;
			}

			cnt = 0;

			for (int i = 0; i < term.size(); i++)
			{
				if (++cnt == k + 1)
				{
					cnt = 1;

					sol++;
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { 4,6 },{ 4,1 },{ 5,2 },{ 2,6 } };

	s.minNumberOfSemesters(6, arr, 4);

	return 0;
}