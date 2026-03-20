#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());

vector<int> ReadPermutation(int n) {
	vector<int> p(n);
	for (int& x : p) {
		scanf("%d", &x);
	}
	return p;
}

bool Check(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
	const int n = A.size();
	for (int i = 0; i < n; ++i) {
		if (C[i] == A[i] || C[i] == B[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);

	const auto& A = ReadPermutation(n);
	const auto& B = ReadPermutation(n);

	vector<int> C(n);
	iota(C.begin(), C.end(), 1);

	for (int iter = 0; iter < 100 && !Check(A, B, C); ++iter) {
		shuffle(C.begin(), C.end(), rnd);
	}

	if (!Check(A, B, C)) {
		printf("IMPOSSIBLE\n");
		return 0;
	}

	for (const int x : C) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}