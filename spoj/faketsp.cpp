#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

int main() {
  vector<pdd> v;

  for (string line; getline(cin, line);) {
    if (line.empty()) {
      continue;
    }

    int j2 = line.size() - 1, i2 = j2;
    while (i2 >= 0 && line[i2] != ',') {
      --i2;
    }
    ++i2;

    int j1 = i2 - 1, i1 = j1;
    while (i1 >= 0 && line[i1] != '(') {
      --i1;
    }
    ++i1;

    string x = line.substr(i1, j1 - i1 + 1);
    string y = line.substr(i2, j2 - i2 + 1);

    v.push_back({stod(x), stod(y)});
  }

  double dis = 0;
  for (int i = 1; i < v.size(); ++i) {
    auto [x1, y1] = v[i - 1];
    auto [x2, y2] = v[i];
    dis += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    printf("The salesman has traveled a total of %.3lf kilometers.\n", dis);
  }

  return 0;
}