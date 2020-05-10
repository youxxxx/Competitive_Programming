#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>

using namespace std;

vector<int> link[201];
int color[201];
bool visited[201];

bool dfs(int cur, int bit)
{
	if (color[cur] != -1 && color[cur] != bit)
	{
		return false;
	}

	bool valid = true;

	color[cur] = bit;

	for (int i = 0; i < link[cur].size(); i++)
	{
		int next;

		next = link[cur][i];

		if (color[next] == -1)
		{
			valid = (valid&&dfs(next, !bit));
		}

		else if(color[next]==color[cur])
		{
			return false;
		}
	}

	return valid;
}

int main()
{
	int n;
	string str;
	char input[201];

	memset(color, -1, sizeof(color));

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (str[j] > str[i])
			{
				link[i].push_back(j);
				link[j].push_back(i);
			}
		}
	}

	bool valid = true;

	string rmin;

	rmin = str;

	for (int i = 0; i < n; i++)
	{
		if (color[i] == -1)
		{
			valid = (valid&&dfs(i,0));
		}

		if(!valid)
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d", color[i]);
	}

	printf("\n");

	return 0;
}