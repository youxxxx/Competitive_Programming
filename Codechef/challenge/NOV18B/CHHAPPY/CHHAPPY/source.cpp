#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n;
	int i;
	int input;
	vector<int> arr;
	bool *visited, *visited2;

	scanf("%d", &t);

	visited = new bool[100001];
	visited2 = new bool[100001];

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		arr.push_back(0);

		for (i = 1; i <= n; i++)
		{
			visited[i] = false;
			visited2[i] = false;

			scanf("%d", &input);

			arr.push_back(input);
		}

		for (i = 1; i <= n; i++)
		{
			if (!visited[arr[i]] && visited2[arr[arr[i]]])
			{
				break;
			}

			visited[arr[i]] = true;
			visited2[arr[arr[i]]] = true;
		}

		if (i <= n)
		{
			printf("Truly Happy\n");
		}

		else
		{
			printf("Poor Chef\n");
		}

		arr.clear();
	}

	return 0;
}