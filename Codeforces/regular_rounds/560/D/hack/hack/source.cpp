#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int list[4] = { 3,5,7,11 };
	int res[4];
	vector<int> arr;
	int i, j, k, l;

	freopen("output.txt", "w", stdout);

	res[0] = 1;

	for (i = 0; i < 3; i++)
	{
		res[1] = res[0];

		for (j = 0; j < 3; j++)
		{
			res[2] = res[1];

			for (k = 0; k < 3; k++)
			{
				res[3] = res[2];

				for (l = 0; l < 3; l++)
				{
					arr.push_back(res[3]);

					res[3] *= list[3];
				}

				res[2] *= list[2];
			}

			res[1] *= list[1];
		}

		res[0] *= list[0];
	}

	arr.erase(arr.begin());
	arr.pop_back();

	printf("%d\n", arr.size());

	for (i = 0; i < arr.size(); i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}