#include<iostream>
#include<cmath>
#include<map>
//#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define pp pair<ll, pair<ll, ll>>

using namespace std;

#define MAX 500005

ll n, k, a;
map<ll, ll> v;

int main(int argc, char **argv) {
/*
#ifndef ONLINE_JUDGE
	freopen("files/test.in", "r", stdin);
#endif
*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	a = (ll)pow(2, 31);
	ll ans = 0;
	while (true) {
		if (n == 0) break;
		while (n >= a) {
			n -= a;
			v[a]++;
			ans++;
		}
		a /= 2;
	}
	if (v.size() > k) {
		while (ans > k) {
			bool found = false;
			for (auto p : v) {
				if (p.second > 1) {
					found = true;
					v[p.first * 2]++;
					v[p.first] -= 2;
					ans--;
					if (!v[p.first]) {
						v.erase(p.first);
					}
					break;
				}
			}
			if (!found && ans > k) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	else {
		while (ans < k) {
			bool found = false;
			for (auto p : v) {
				if (p.first % 2 == 0 && p.second > 0) {
					found = true;
					v[p.first / 2] += 2;
					v[p.first]--;
					ans++;
					if (!v[p.first]) {
						v.erase(p.first);
					}
					break;
				}
			}
			if (!found && ans < k) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (auto p : v) {
		for (int i = 0; i < p.second; ++i) {
			cout << p.first << " ";
		}
	}

	return 0;
}