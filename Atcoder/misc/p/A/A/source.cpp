#include<cstdio>

using namespace std;

int main()
{
	int a, b, c;
	char input[101];

	scanf("%d %d %d", &a, &b, &c);

	scanf("%s", input);

	printf("%d %s\n", a + b + c, input);

	return 0;
}