#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	int input, cur = 0;
	//vector<int> book;
	int *index;
	bool *visited;

	scanf("%d", &n);

	visited = new bool[n + 1];
	index = new int[n + 1];

	for (i = 0; i < n; i++)
	{
		visited[i + 1] = false;

		scanf("%d", &input);

		//book.push_back(input);

		index[input] = i + 1;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (index[input] > cur)
		{
			printf("%d ", index[input] - cur);

			cur = index[input];
		}

		else
		{
			printf("0 ");
		}
	}

	return 0;
}