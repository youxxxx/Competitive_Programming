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
		int n;

		scanf("%d", &n);

		int lmin = 0;

		int arr[101];

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);

			lmin = max(lmin, arr[i]);
		}

		{
			int odd = 0;

			int curmax = 0;

			for (int i = 0; i < n; i++) {
				odd = odd || (arr[i] % 2);

				curmax = max(curmax, arr[i] / 2);
			}

			lmin = min(lmin, curmax + odd);
		}

		{
			int check[3] = { 0, };

			int curmax = 0;

			for (int i = 0; i < n; i++) {
				check[arr[i] % 3] = check[arr[i] % 3] || 1;

				curmax = max(curmax, arr[i] / 3);
			}

			lmin = min(lmin, curmax + check[1] + check[2]);

			if (curmax > 1) {
				bool valid = true;

				for (int i = 0; i < n; i++) {
					if (arr[i] / 3 == curmax&&arr[i] % 3) {
						valid = false;
						
						break;
					}
				}

				if (valid) {
					lmin = min(lmin, curmax + 1);
				}
			}
		}

		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j <= 5; j++) {
				for (int k = 0; k <= 5; k++) {
					bool valid = true;

					for (int l = 0; l < n; l++) {
						bool found = false;;

						for (int i2 = 0; i2 <= i; i2++) {
							for (int j2 = 0; j2 <= j; j2++) {
								for (int k2 = 0; k2 <= k; k2++) {
									if (i2 + 2 * j2 + 3 * k2 == arr[l]) {
										found = true;

										break;
									}
								}

								if (found) {
									break;
								}
							}

							if (found) {
								break;
							}
						}

						if (!found) {
							valid = false;

							break;
						}
					}

					if (valid) {
						lmin = min(lmin, i + j + k);
					}
				}
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}