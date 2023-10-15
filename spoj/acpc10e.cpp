#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  ll g, t, a, d;
  scanf("%lld%lld%lld%lld", &g, &t, &a, &d);

  if (g == -1) {
    exit(0);
  }

  ll games = g * t * (t - 1) / 2;

  ll teams = g * a + d;
  ll teams_to_add = 0;

  while (__builtin_popcountll(teams) != 1) {
    ll cnt = teams & -teams;
    teams += cnt;
    teams_to_add += cnt;
  }

  for (; teams != 1; teams /= 2) {
    games += teams / 2;
  }

  return to_string(g) + "*" + to_string(a) + "/" + to_string(t) + "+" + to_string(d) + "=" + to_string(games) + "+" + to_string(teams_to_add);
}

int main() {
  while (true) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}