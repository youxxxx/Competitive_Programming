#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	printf("%d\n", n*n + (n - 1)*(n - 1));

	return 0;
}