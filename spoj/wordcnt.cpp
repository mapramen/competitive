#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t != 0) {
    int current_length = 0, current_length_cnt = 0, max_cnt = 0;

    int length = 0;
    while (true) {
      char c = getchar();
      if (isalpha(c)) {
        ++length;
        continue;
      }

      if (length != 0) {
        if (length != current_length) {
          current_length = length, current_length_cnt = 0;
        }

        if (current_length != 0) {
          ++current_length_cnt;
        }

        max_cnt = max(max_cnt, current_length_cnt);
        length = 0;
      }

      if (c == '\n' || c == EOF) {
        break;
      }
    }

    if (max_cnt == 0) {
      continue;
    }

    printf("%d\n", max_cnt);
    --t;
  }
  return 0;
}