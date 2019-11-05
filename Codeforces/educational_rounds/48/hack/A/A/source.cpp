#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	FILE *out;
	int i;

	out = fopen("hack_A_1.txt", "w");

	fprintf(out, "200000 1\n");

	for (i = 0; i < 200000; i++)
	{
		fprintf(out, "1000000000 ");
	}

	return 0;
}