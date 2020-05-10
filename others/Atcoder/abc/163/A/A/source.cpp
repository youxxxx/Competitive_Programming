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
	const double pi = 3.141592653589793;

	scanf("%d", &n);

	printf("%.10lf\n", pi*(double)(n * 2));

	return 0;
}