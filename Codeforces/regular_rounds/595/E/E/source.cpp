#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	long long n, c;
	long long i;
	vector<long long> st, el;
	long long input;
	long long s[2], e[2];

	//freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &n, &c);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%lld", &input);

		st.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%lld", &input);

		el.push_back(input);
	}

	printf("0");

	s[1] = st[0];
	e[1] = el[0] + c;

	for (i = 1; i < n - 1; i++)
	{
		printf(" %lld", s[i % 2] < e[i % 2] ? s[i % 2] : e[i % 2]);

		s[!(i % 2)] = (s[i % 2] < e[i % 2] ? s[i % 2] : e[i % 2]) + st[i];

		e[!(i % 2)] = (s[i % 2] + c < e[i % 2] ? s[i % 2] + c : e[i % 2]) + el[i];
	}

	printf(" %lld", s[!(n % 2)] < e[!(n % 2)] ? s[!(n % 2)] : e[!(n % 2)]);
	
	return 0;
}