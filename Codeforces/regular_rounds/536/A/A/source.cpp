#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>


using namespace std;

int main()
{
	int n;
	vector<string> mat;
	string str;
	char input[1000];
	int i, j, k;
	int dx[5] = { -1,-1,0,1,1 };
	int dy[5] = { -1,1,0,-1,1 };
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		mat.push_back(str);
	}

	if (n < 3)
	{
		printf("0\n");

		return 0;
	}

	for (i = 1; i < n - 1; i++)
	{
		for (j = 1; j < n - 1; j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (mat[i + dx[k]][j + dy[k]] != 'X')
				{
					break;
				}
			}

			if (k == 5)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}