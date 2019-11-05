#include<cstdio>
#include<cmath>
#include<vector>
#include<map>

using namespace std;

int main()
{
	int n;
	long long int k;
	vector<long long int> arr;
	vector<int> pw;
	long long int **sheet;
	long long int base;
	//set<int> pw;
	map<long long int, long long int>::iterator it;
	int input;
	long long int sum = 0;
	int i, j;

	scanf("%d %I64d", &n, &k);

	sheet = new long long int*[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back((long long int)input%k);

		//pw.push_back((int)(pow(10.0, (int)log10((double)input) + 1)));
		pw.push_back((int)log10((double)input) + 1);

		sheet[i] = new long long int[10];

		base = input%k;

		for (j = 0; j < 10; j++)
		{
			sheet[i][j] = base;

			base = (base * 10) % k;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			sum += !((sheet[i][pw[j]] + arr[j]) % k);
		}
	}

	printf("%I64d", sum);

	return 0;
}