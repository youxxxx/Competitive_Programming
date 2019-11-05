#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int i, j;
	vector<int> arr;
	int input;
	int sum = 0;
	int cand;
	int val;
	int min = 10000000, minlen;
	double avg;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		sum += input;
	}

	for (i = 1; i <= 100; i++)
	{
		cand = 0;

		for (j = 0; j < n; j++)
		{
			val = abs(i - arr[j]);

			if (val > 1)
			{
				cand += val - 1;
			}
		}

		if (cand < min)
		{
			min = cand;

			minlen = i;
		}
	}
	
	printf("%d %d\n", minlen, min);

	return 0;
}