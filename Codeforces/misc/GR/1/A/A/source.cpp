#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int b, k;
	int base = 1;
	int odd = 0;
	int i;
	int input;
	vector<int> arr;

	scanf("%d %d", &b, &k);
	
	for (i = 0; i < k; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < k; i++)
	{
		odd += (arr[k - i - 1] * base) % 2;

		base *= b;
	}

	if (odd % 2)
	{
		printf("odd\n");
	}

	else
	{
		printf("even\n");
	}

	return 0;
}