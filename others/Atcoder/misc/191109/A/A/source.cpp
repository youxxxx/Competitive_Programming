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

	printf("%d\n", n / 2 - !(n % 2));

	return 0;
}