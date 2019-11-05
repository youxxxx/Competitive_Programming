#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	int *part;
	vector<int> *arr;
	int input1, input2, temp, temp2;
	int idx;

	scanf("%d", &n);

	part = new int[n + 1];
	arr = new vector<int>[n + 1];

	for (i = 1; i <= n; i++)
	{
		part[i] = -1;

		arr[i].push_back(i);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (part[input1] == -1 && part[input2] == -1)
		{
			idx = part[input1] = part[input2] = input1;

			arr[input1].push_back(input2);
		}

		else if (part[input2] == -1)
		{
			temp = part[input1];

			while (temp != part[temp])
			{
				arr[temp].clear();

				temp = part[temp];
			}

			idx = part[input2] = part[input1] = temp;

			arr[temp].push_back(input2);
		}

		else if (part[input1] == -1)
		{
			temp = part[input2];

			while (temp != part[temp])
			{
				arr[temp].clear();

				temp = part[temp];
			}

			idx = part[input1] = part[input2] = temp;

			arr[temp].push_back(input1);
		}

		else
		{
			temp = part[input1];

			while (temp != part[temp])
			{
				arr[temp].clear();

				temp = part[temp];
			}

			temp2 = part[input2];

			while (temp2 != part[temp2])
			{
				arr[temp2].clear();
				
				temp2 = part[temp2];
			}

			arr[temp].insert(arr[temp].end(), arr[part[temp2]].begin(), arr[part[temp2]].end());

			part[temp2] = temp;

			arr[temp2].clear();

			idx = part[input2] = part[input1] = temp;
		}
	}

	while (part[idx] != idx)
	{
		idx = part[idx];
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[idx][i]);
	}
		
	return 0;
}