#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[100];
	string str, gen = "ACTG";
	int n;
	int i, j;
	int lmin = 99999999, cand1, cand2, cand;

	scanf("%d", &n);
	scanf("%s", input);
	str = input;

	for (i = 0; i < n - 3; i++)
	{
		cand = 0;

		for (j = 0; j < 4; j++)
		{
			//cand1 = (26 + (str[i + j] - 'A') - (gen[i] - 'A')) % 26;
			//cand2 = (26 + (gen[i] - 'A') - (str[i + j] - 'A')) % 26;

			cand1 = abs(str[i + j] - gen[j]);
			cand2 = 26 - cand1;

			cand += cand1 < cand2 ? cand1 : cand2;
		}

		if (cand < lmin)
		{
			lmin = cand;
		}
	}

	printf("%d\n", lmin);

	return 0;
}