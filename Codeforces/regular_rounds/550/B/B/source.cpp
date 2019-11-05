#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> even, odd;
	int i;
	int input;
	int size;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (!(input % 2))
		{
			even.push_back(input);
		}
		
		else
		{
			odd.push_back(input);
		}
	}

	if (even.size() == odd.size())
	{
		printf("0\n");

		return 0;
	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());

	if (even.size() < odd.size())
	{
		for (i = 0; i < odd.size() - even.size() - 1; i++)
		{
			sum += odd[i];
		}
	}

	else
	{
		for (i = 0; i < even.size() - odd.size() - 1; i++)
		{
			sum += even[i];
		}
	}

	printf("%d\n", sum);

	return 0;
}