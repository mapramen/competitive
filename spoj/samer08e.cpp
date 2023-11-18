#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GregorianDateToJulianDayNumber(int date, int month, int year) {
  return (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + date - 32075;
}

pii Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<pii> a;
  while (n--) {
    int date, month, year, consumption;
    scanf("%d%d%d%d", &date, &month, &year, &consumption);
    a.push_back({GregorianDateToJulianDayNumber(date, month, year), consumption});
  }
  sort(a.begin(), a.end());

  int number_of_days = 0, consumption = 0;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].first == a[i - 1].first + 1) {
      ++number_of_days, consumption += a[i].second - a[i - 1].second;
    }
  }

  return {number_of_days, consumption};
}

int main() {
  while (true) {
    auto [number_of_days, consumption] = Solve();
    printf("%d %d\n", number_of_days, consumption);
  }
  return 0;
}