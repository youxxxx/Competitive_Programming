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

class MyHashMap {
public:
	int arr[1000001];

	/** Initialize your data structure here. */
	MyHashMap() {
		memset(arr, -1, sizeof(arr));
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		arr[key] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return arr[key];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		arr[key] = -1;
	}
};

int main()
{

}