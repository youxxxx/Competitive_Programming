#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	double prob[500001];
	double acc[250001];
	double sol = 0.0;
	double base = 0.0;
	char input[500001];
	string str;
	int n;
	int i;

	scanf("%s", input);
	str = input;
	n = str.size();

	if (n % 2)
	{
		acc[n/2+1] = base = 1.0 / (double)(n / 2 + 1);
	}

	else
	{
		acc[n / 2 + 1] = 0.0;
	}

	for (i = n / 2; i >= 1; i--)
	{
		base += 1.0 / (double)i + (1.0 / (double)(n - i + 1));
		
		acc[i] = acc[i + 1] + 1.0 / (double)(i) + 1.0 / (double)(n - i + 1);
	}

	prob[1] = prob[n] = acc[1];

	for (i = 2; i <= n / 2; i++)
	{
		prob[i] = prob[n - i + 1] = prob[i - 1] + acc[i];
	}

	if (n % 2)
	{
		prob[n / 2 + 1] = prob[n / 2] + acc[n / 2 + 1];
	}

	for (i = 0; i < n; i++)
	{ 
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y')
		{
			sol += prob[i + 1];
		}
	}

	printf("%.8lf", sol);

	return 0;
}