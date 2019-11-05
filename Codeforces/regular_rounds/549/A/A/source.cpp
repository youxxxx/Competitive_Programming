#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	vector<int> arr;
	int input;
	int door;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);
		
		arr.push_back(input);
	}

	if (n == 1)
	{
		printf("1\n");

		return 0;
	}

	door = arr.back();

	for (i = n - 2; i >= 0; i--)
	{
		if (arr[i] != door)
		{
			break;
		}
	}

	printf("%d\n", i + 1);

	return 0;
}