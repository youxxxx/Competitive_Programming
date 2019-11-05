#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int hd, ld;
	double h, l;
	double sol;

	scanf("%d %d", &hd, &ld);

	h = (double)hd;
	l = (double)ld;

	sol = (l*l - h*h) / ((double)2.0*h);

	printf("%.9lf\n", sol);

	return 0;
}