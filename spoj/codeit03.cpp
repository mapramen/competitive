#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string GetDayOfTheWeek(int day, int month, int year) {
  // 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday
  int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

  year -= month < 3;
  int res = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

  switch (res) {
    case 0:
      return "Sunday";
    case 1:
      return "Monday";
    case 2:
      return "Tuesday";
    case 3:
      return "Wednesday";
    case 4:
      return "Thursday";
    case 5:
      return "Friday";
    case 6:
      return "Saturday";
  }

  return "";
}

string Solve() {
  int date, month, year;
  scanf("%d%d%d", &date, &month, &year);
  return GetDayOfTheWeek(date, month, year);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}