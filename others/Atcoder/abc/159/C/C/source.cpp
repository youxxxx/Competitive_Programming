#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	double sol;

	sol = (double)n / 3.0;

	printf("%.7lf", sol*sol*sol);

	return 0;
}