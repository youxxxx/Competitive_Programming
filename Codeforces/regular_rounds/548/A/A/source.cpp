#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n;
	char input[100000];
	int i;
	long long sum = 0;
	string str;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (!((str[i] - '0') % 2))
		{
			sum += i + 1;
		}
	}

	printf("%I64d\n", sum);

	return 0;
}