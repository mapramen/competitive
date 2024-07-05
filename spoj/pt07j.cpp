#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

struct Node {
	int count;
	Node* leftChild;
	Node* rightChild;

	Node(int count = 0, Node* leftChild = NULL, Node* rightChild = NULL) {
		this->count = count;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}
};

int GetCount(Node* a) {
	return a == NULL ? 0 : a->count;
}

int GetCount(Node* a, Node* b) {
	return GetCount(b) - GetCount(a);
}

Node* GetLeftChild(Node* a) {
	return a == NULL ? NULL : a->leftChild;
}

Node* GetRightChild(Node* a) {
	return a == NULL ? NULL : a->rightChild;
}

Node* Insert(int l, int r, Node* node, int x) {
	if (x < l || r < x) {
		return node;
	}

	if (l == r) {
		return new Node(GetCount(node) + 1);
	}

	int mid = l + (r - l) / 2;

	return new Node(
			GetCount(node) + 1,
			Insert(l, mid, GetLeftChild(node), x),
			Insert(mid + 1, r, GetRightChild(node), x));
}

int Query(int l, int r, Node* a, Node* b, int k) {
	if (l == r) {
		return l;
	}

	int mid = l + (r - l) / 2;
	int left_count = GetCount(GetLeftChild(b)) - GetCount(GetLeftChild(a));

	return left_count >= k
						 ? Query(l, mid, GetLeftChild(a), GetLeftChild(b), k)
						 : Query(mid + 1, r, GetRightChild(a), GetRightChild(b), k - left_count);
}

vector<vector<int>> adj(N);
int label[N], label_to_vertex[N];
int start_time[N], end_time[N], start_time_to_vertex[N], timer = 0;

void DFS(int i, int p) {
	start_time[i] = ++timer;
	start_time_to_vertex[start_time[i]] = i;
	for (int j : adj[i]) {
		if (j == p) {
			continue;
		}
		DFS(j, i);
	}
	end_time[i] = timer;
}

Node* roots[N];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &label[i]);
	}

	for (int e = 1; e < n; ++e) {
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	vector<int> sorted_label = vector<int>(label, label + n + 1);
	sorted_label.push_back(INT_MIN);

	sort(sorted_label.begin(), sorted_label.end());
	sorted_label.erase(unique(sorted_label.begin(), sorted_label.end()), sorted_label.end());

	for (int i = 1; i <= n; ++i) {
		label[i] = lower_bound(sorted_label.begin(), sorted_label.end(), label[i]) - sorted_label.begin();
		label_to_vertex[label[i]] = i;
	}

	DFS(1, 0);

	int m = sorted_label.size();
	for (int i = 1; i <= n; ++i) {
		roots[i] = Insert(1, m, roots[i - 1], label[start_time_to_vertex[i]]);
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		int i, k;
		scanf("%d%d", &i, &k);

		int x = Query(1, m, roots[start_time[i] - 1], roots[end_time[i]], k);
		printf("%d\n", label_to_vertex[x]);
	}
}