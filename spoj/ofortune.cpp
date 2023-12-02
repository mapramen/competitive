#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll CompoundOperation(ll principal, ll years, double annual_interest_rate, ll annual_operation_charge) {
  while (years--) {
    ll interest = annual_interest_rate * principal;
    principal += interest;
    principal -= annual_operation_charge;
  }
  return principal;
}

ll SimpleOperation(ll principal, ll years, double annual_interest_rate, ll annual_operation_charge) {
  ll interest = 0;
  while (years--) {
    interest += annual_interest_rate * principal;
    principal -= annual_operation_charge;
  }
  return principal + interest;
}

ll Solve() {
  ll principal, years;
  scanf("%lld%lld", &principal, &years);

  int options;
  scanf("%d", &options);

  ll ans = LLONG_MIN;
  while (options--) {
    int operation_type;
    double annual_interest_rate;
    ll annual_operation_charge;

    scanf("%d%lf%lld", &operation_type, &annual_interest_rate, &annual_operation_charge);

    if (operation_type == 0) {
      ans = max(ans, SimpleOperation(principal, years, annual_interest_rate, annual_operation_charge));
    } else {
      ans = max(ans, CompoundOperation(principal, years, annual_interest_rate, annual_operation_charge));
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}