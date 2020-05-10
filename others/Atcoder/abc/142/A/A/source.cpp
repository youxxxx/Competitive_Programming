#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	
	printf("%.8lf", (double)(n / 2 + n % 2) / (double)n);

	return 0;
}