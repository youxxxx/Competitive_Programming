#include<cstdio>
#include<cmath>
#include<vector>
#include<string>


using namespace std;

int main()
{
	long long n;
	string str;
	char input[100001];
	long long cnt[26] = { 0, };
	long long i, j;
	long long prod = 1;

	scanf("%lld %s", &n, input);

	str = input;

	for (i = 0; i < n; i++)
	{
		cnt[str[i] - 'a']++;
	}

	for (i = 0; i < 26; i++)
	{
		prod = (prod*(cnt[i] + 1)) % 1000000007;
	}

	printf("%lld\n", prod - 1);

	return 0;
}