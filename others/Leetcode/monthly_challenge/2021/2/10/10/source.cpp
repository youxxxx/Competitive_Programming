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

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	map<Node*, int> list;
	vector<Node*> arr;
	Node *sol;

	Node* copyRandomList(Node* head) {
		if (!head) {
			return 0;
		}

		Node *cur = head;
		sol = new Node(head->val);
		Node *ptr = sol;
		arr.push_back(sol);
		list[head] = 0;
		int cnt = 1;

		while (cur->next) {
			ptr->next = new Node(cur->next->val);

			cur = cur->next;

			ptr = ptr->next;

			list[cur] = cnt++;

			arr.push_back(ptr);
		}

		cur = head;
		ptr = sol;

		while (cur) {
			if (!cur->random) {
				ptr->random = NULL;
			}

			else {
				ptr->random = arr[list[cur->random]];
			}

			cur = cur->next;

			ptr = ptr->next;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}