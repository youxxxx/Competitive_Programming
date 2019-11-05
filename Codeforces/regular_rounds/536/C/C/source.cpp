#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>


using namespace std;

int main()
{
	int n;
	vector<long long> arr;
	int i;
	long long sum = 0, input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n / 2; i++)
	{
		sum += (arr[i] + arr[n - 1 - i])*(arr[i] + arr[n - 1 - i]);
	}
	
	printf("%I64d\n", sum);

	return 0;
}