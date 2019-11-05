#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	vector<int> arr;
	vector<int> cand[2];
	vector<bool> erase;
	int i, j;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	arr.insert(arr.begin(), 0);

	cand[1].push_back(1);

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < cand[i%2].size(); j++)
		{
			if (arr[i - cand[i % 2][j]] - arr[i - cand[i % 2][j] + 1] != arr[i] - arr[i + 1])
			{
				erase.push_back(true);
			}

			else
			{
				erase.push_back(false);
			}
		}

		for (j = 0; j < cand[i % 2].size(); j++)
		{
			if (!(erase[j]))
			{
				cand[!(i % 2)].push_back(cand[i % 2][j]);
			}
		}

		cand[!(i % 2)].push_back(i + 1);

		cand[i % 2].clear();
		erase.clear();
	}

	//cand[(n % 2)].push_back(n);

	printf("%d\n", cand[(n % 2)].size());

	for (i = 0; i < cand[(n % 2)].size(); i++)
	{
		printf("%d ", cand[(n % 2)][i]);
	}

	return 0;
}