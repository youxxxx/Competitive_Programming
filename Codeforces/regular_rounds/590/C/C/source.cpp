#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<deque>

using namespace std;

int main()
{
	int tc, cases;
	vector<string> arr;
	string str;
	char input[200001];
	int n;
	int row;
	int i;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		arr.clear();

		scanf("%s", input);
		str = input;
		arr.push_back(str);

		scanf("%s", input);
		str = input;
		arr.push_back(str);

		row = 0;

		for (i = 0; i < n - 1; i++)
		{
			if (arr[row][i] <= '2')
			{
				continue;
			}

			else
			{
				if (arr[!row][i] >= '3')
				{
					row = !row;

					continue;
				}
			}

			break;
		}

		if (i == n - 1 && (row == 1 && arr[1][n - 1] <= '2' || row == 0 && arr[0][n - 1] >= '3' && arr[1][n - 1] >= '3'))
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}