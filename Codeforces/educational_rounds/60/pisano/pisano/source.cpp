#include<cstdio>

using namespace std;

long long get_pisano_period(long long m) {
	long long a = 0, b = 1, c = a + b;
	for (int i = 0; i < m * m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1) return i + 1;
	}
}

int main()
{
	FILE *fp;

	fp = fopen("output.txt", "w");

	fprintf(fp, "%lld\n", get_pisano_period(1000000007));

	return 0;
}