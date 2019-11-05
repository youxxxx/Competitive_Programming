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
	int k;
	int input1, input2;
	vector<int> arr;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		arr.push_back(input2);
	}

	scanf("%d", &k);
	
	for (i = 0; i < n; i++)
	{
		if (k <= arr[i])
		{
			break;
		}
	}

	printf("%d\n", n - i);

	return 0;
}