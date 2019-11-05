#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>

#define LMAX 200001
#define SMAX 400001

using namespace std;

class state
{
public:
	int len;
	int link;
	map<char, int> delta;
	int pos;
	bool clone;
	bool final;
	vector<int> inv;

	state()
	{
		clone = false;

		final = false;
	}
};

class suffix_aut
{
public:
	state s[SMAX];
	int size;
	long long icnt[LMAX];
	long long ocnt[LMAX];

	suffix_aut(string str)
	{
		int i;
		int last, cur, p, q, dup;
		char ch;

		size = 1;

		s[0].len = 0;
		s[0].link = -1;
		last = 0;

		memset(ocnt, 0, sizeof(ocnt));
		memset(icnt, 0, sizeof(icnt));

		for (i = 0; i < str.size(); i++)
		{
			cur = size++;

			s[cur].len = s[last].len + 1;
			s[cur].pos = s[cur].len - 1;

			ch = str[i];

			p = last;

			while (p != -1 && !s[p].delta.count(ch))
			{
				s[p].delta[ch] = cur;

				p = s[p].link;
			}
			
			if (p == -1)
			{
				s[cur].link = 0;
			}

			else
			{
				q = s[p].delta[ch];

				if (s[p].len + 1 == s[q].len)
				{
					s[cur].link = q;
				}

				else
				{
					dup = size++;

					s[dup].clone = true;

					s[dup].len = s[p].len + 1;
					s[dup].link = s[q].link;
					s[dup].delta = s[q].delta;
					s[dup].pos = s[q].pos;

					while (p != -1 && s[p].delta[ch] == q)
					{
						s[p].delta[ch] = dup;

						p = s[p].link;
					}

					s[q].link = s[cur].link = dup;
				}
			}

			last = cur;
		}

		p = last;

		while (p != -1)
		{
			s[p].final = true;

			p = s[p].link;
		}

		for (i = 0; i < size; i++)
		{
			if (s[i].link != -1)
			{
				s[s[i].link].inv.push_back(i);
			}
		}
	}

	void st_find(int target, int size)
	{
		int i;

		if (!s[target].clone)
		{
			icnt[s[target].pos - size + 1]++;
		}

		for (i = 0; i < s[target].inv.size(); i++)
		{
			st_find(s[target].inv[i], size);
		}
	}


	void find(int target, int size)
	{
		int i;

		if (!s[target].clone)
		{
			ocnt[s[target].pos + 1]++;

			icnt[s[target].pos - size + 1]++;
		}

		for (i = 0; i < s[target].inv.size(); i++)
		{
			find(s[target].inv[i], size);
		}
	}

	void find(int target, vector<int> &res)
	{
		int i;

		if (!s[target].clone)
		{
			res.push_back(s[target].pos);
		}

		for (i = 0; i < s[target].inv.size(); i++)
		{
			find(s[target].inv[i], res);
		}
	}

	void occurence(string str)
	{
		int target = 0;
		int i;

		for (i = 0; i < str.size(); i++)
		{
			target = s[target].delta[str[i]];
		}

		find(target, str.size());
	}

	void st_occurence(string str)
	{
		int target = 0;
		int i;

		for (i = 0; i < str.size(); i++)
		{
			target = s[target].delta[str[i]];
		}

		st_find(target, str.size());
	}

	void occurence(string str, vector<int> &res)
	{
		int target = 0;
		int i;

		for (i = 0; i < str.size(); i++)
		{
			target = s[target].delta[str[i]];
		}

		find(target, res);
	}
};


int main()
{
	char input[200001];
	string str, t;
	vector<string> arr;
	vector<int> strsize;
	vector<int> temp;
	int i, j;
	suffix_aut *suf;
	int n;
	long long sol = 0;

	scanf("%s", input);
	str = input;
	t = str;

	suf = new suffix_aut(str);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);
		str = input;

		suf->occurence(str);
		//suf->st_occurence(str);

		arr.push_back(str);
		strsize.push_back(str.size());
	}

	for (j = 0; j < t.size(); j++)
	{
		sol += suf->icnt[j] * suf->ocnt[j];
	}

	printf("%lld\n", sol);

	return 0;
}