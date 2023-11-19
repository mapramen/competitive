#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve(double principal, double annual_interest_rate, int intervals) {
  annual_interest_rate /= 100.0;

  double interest_rate = annual_interest_rate / intervals;
  while (intervals--) {
    double interest = principal * interest_rate;
    interest = floor(100 * interest) / 100.0;
    principal += interest;
  }

  return principal;
}

int main() {
  for (int k = 1;; ++k) {
    double principal, annual_interest_rate;
    int intervals;

    scanf("%lf%lf%d", &principal, &annual_interest_rate, &intervals);

    if (intervals == 0) {
      break;
    }

    printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n", k, principal, annual_interest_rate, intervals, Solve(principal, annual_interest_rate, intervals));
  }
  return 0;
}