#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define ALPHABET_SIZE 26

vector<char> A = {'a', 'e', 'i', 'o', 'u'};
vector<char> B = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

char GetEncryptedChar(char c, int k) {
  if (find(A.begin(), A.end(), c) == A.end()) {
    swap(A, B);
  }

  int i = find(A.begin(), A.end(), c) - A.begin();
  int x = A.size() * (k - 1) + i;

  return B[x % B.size()];
}

string Solve() {
  string s;
  cin >> s;

  vector<int> cnt(ALPHABET_SIZE);

  for (char& c : s) {
    int k = c - 'a';
    ++cnt[k];
    c = GetEncryptedChar(c, cnt[k]);
  }

  return s;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}