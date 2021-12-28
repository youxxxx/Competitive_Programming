#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++) {
		long long n, k, x;

		scanf("%lld %lld %lld", &n, &k, &x);

		char input[2001];
		scanf("%s", input);
		const string str = input;

		vector<pair<char,long long>> arr;

		char prev = ' ';

		for (int i = 0; i < n; i++) {
			if (str[i] != prev) {
				prev = str[i];

				arr.push_back({ str[i],1 });

				continue;
			}

			arr.back().second++;
		}

		x--;

		string sol;

		for (int i = (int)arr.size() - 1; i >= 0; i--) {
			if (arr[i].first == 'a') {
				for (int j = 0; j < arr[i].second; j++) {
					sol.push_back('a');
				}

				continue;
			}

			for (long long j = 0; j < x % (arr[i].second*k+1); j++) {
				sol.push_back('b');
			}

			x /= (arr[i].second*k+1);
		}

		reverse(sol.begin(), sol.end());

		printf("%s\n", sol.c_str());
	}

	return 0;
}