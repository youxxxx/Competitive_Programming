#include<cstdio>

using namespace std;

int main()
{
	int am, as, bm, bs;
	int a, b, c;
	int m, s;

	scanf("%d:%d", &am, &as);
	scanf("%d:%d", &bm, &bs);

	a = am * 60 + as;
	b = bm * 60 + bs;

	if (a <= b)
	{
		c = (a + b) / 2;
	}

	else
	{
		c = ((a + b + 1440) / 2) % 1440;
	}

	m = c / 60;
	s = c % 60;

	printf("%02d:%02d\n", m, s);

	return 0;
}