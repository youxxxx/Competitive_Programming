#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<stack>
#include<queue>

class CustomStack {
public:
	int arr[1001];
	int top;
	int size;

	CustomStack(int maxSize) {
		size = maxSize;
		top = 0;
	}

	void push(int x) {
		if (top != size) {
			arr[top++] = x;
		}
	}

	int pop() {
		if (!top) {
			return -1;
		}

		else {
			return arr[--top];
		}
	}

	void increment(int k, int val) {
		for (int i = 0; i < k; i++) {
			arr[i] += val;
		}
	}
};


using namespace std;

int main()
{
}