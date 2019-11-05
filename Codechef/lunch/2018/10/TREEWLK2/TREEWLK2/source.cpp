#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	vector<int> *tree;
	int t, z;
	int n, k, l;
	int a, b;
	int aptr, bptr;
	int i, j;
	int *level, *parent;
	vector<int> upath, vpath;
	vector<int> realu, realv;
	vector<int> temp, temp2;
	queue<pair<int, int>> q;
	pair<int, int> cur;
	int cnt;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %d", &n, &k, &l);

		tree = new vector<int>[n + 1];

		level = new int[n + 1];

		parent = new int[n + 1];

		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &a, &b);

			tree[a].push_back(b);
			tree[b].push_back(a);
		}

		for (i = 1; i <= n; i++                  
		{
			level[i] = -1;
		}

		cnt = 0;

		parent[1] = -1;

		q.push(pair<int, int>(0, 1));

		while (!q.empty())
		{
			cur = q.front();

			q.pop();

			level[cur.second] = cur.first;

			for (i = 0; i < tree[cur.second].size(); i++)
			{
				if (level[tree[cur.second][i]] == -1)
				{
					q.push(pair<int, int>(cur.first + 1, tree[cur.second][i]));

					parent[tree[cur.second][i]] = cur.second;
				}
			}
		}

		for (i = 0; i < k; i++)
		{
			scanf("%d", &a);

			upath.push_back(a);
		}

		for (i = 0; i < l; i++)
		{
			scanf("%d", &a);

			vpath.push_back(a);
		}

		//realu.push_back(upath[0]);

		for (i = 0; i < k - 1; i++)
		{
			a = upath[i];
			b = upath[i + 1];

			aptr = 0;
			bptr = 0;

			while (level[a] > level[b])
			{
				//temp.insert(temp.begin() + aptr++, a);

				temp2.push_back(a);

				a = parent[a];
			}

			while (level[a] < level[b])
			{
				temp.insert(temp.begin() + aptr, b);

				b = parent[b];
			}

			while (a != b)
			{
				//temp.insert(temp.begin() + aptr++, a);

				temp2.push_back(a);

				a = parent[a];

				temp.insert(temp.begin() + aptr, b);

				b = parent[b];
			}

			temp2.push_back(a);
			//temp2.push_back(upath[i]);
			//temp.push_back(upath[i + 1]);

			for (j = 0; j < temp2.size(); j++)
			{
				realu.push_back(temp2[j]);
			}
			
			for (j = 0; j < temp.size() - 1; j++)
			{
				realu.push_back(temp[j]);
			}
			

			//realu.emplace_back(temp2);
			//realu.emplace_back(temp);

			temp2.clear();
			temp.clear();
		}

		realu.push_back(upath[k - 1]);

		//realv.push_back(vpath[0]);

		for (i = 0; i < l - 1; i++)
		{
			a = vpath[i];
			b = vpath[i + 1];

			aptr = 0;
			bptr = 0;

			while (level[a] > level[b])
			{
				//temp.insert(temp.begin() + aptr++, a);

				temp2.push_back(a);

				a = parent[a];
			}

			while (level[a] < level[b])
			{
				temp.insert(temp.begin() + aptr, b);

				b = parent[b];
			}

			while (a != b)
			{
				//temp.insert(temp.begin() + aptr++, a);

				temp2.push_back(a);

				a = parent[a];

				temp.insert(temp.begin() + aptr, b);

				b = parent[b];
			}

			temp2.push_back(a);
			//temp2.push_back(vpath[i]);
			//temp.push_back(vpath[i + 1]);

			for (j = 0; j < temp2.size(); j++)
			{
				realv.push_back(temp2[j]);
			}

			for (j = 0; j < temp.size() - 1; j++)
			{
				realv.push_back(temp[j]);
			}

			//realv.emplace_back(temp2);
			//realv.emplace_back(temp);

			temp2.clear();
			temp.clear();
		}

		realv.push_back(vpath[l - 1]);

		for (i = 0; i < realu.size() - 1 && i < realv.size() - 1; i++)
		{
			if (realu[i] == realv[i])
			{
				cnt++;
			}

			if (realu[i] == realv[i + 1])
			{
				cnt++;
			}

			if (realu[i + 1] == realv[i])
			{
				cnt++;
			}
		}

		if (realu[i] == realv[i])
		{
			cnt++;
		}

		delete[] parent;
		delete[] level;
		delete[] tree;
		realv.clear();
		realu.clear();
		vpath.clear();
		upath.clear();

		printf("%d\n", cnt);
	}

	return 0;
}