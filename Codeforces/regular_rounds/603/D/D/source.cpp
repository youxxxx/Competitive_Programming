#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	vector<int> edge[26], graph[200001];
	int n;
	bool visited[200001] = { 0, };
	bool visitedletter[26] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char input[100];
		string str;
		bool exist[26] = { 0, };

		scanf("%s", &input);

		str = input;

		for (int j = 0; j < str.size(); j++)
		{
			exist[str[j] - 'a'] = true;
		}

		for (int j = 0; j < 26; j++)
		{
			if (exist[j])
			{
				graph[i].push_back(j);

				edge[j].push_back(i);
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		stack<int> s;
		
		if (!visited[i])
		{
			cnt++;

			visited[i] = true;

			s.push(i);

			while (!s.empty())
			{
				int cur;

				cur = s.top();
				s.pop();

				for (int j = 0; j < graph[cur].size(); j++)
				{
					int nextletter;

					nextletter = graph[cur][j];

					if (!visitedletter[nextletter])
					{
						visitedletter[nextletter] = true;

						for (int k = 0; k < edge[nextletter].size(); k++)
						{
							int next;

							next = edge[nextletter][k];

							if (!visited[next])
							{
								visited[next] = true;

								s.push(next);
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}