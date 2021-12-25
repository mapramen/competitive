#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pii,int>
#define plp pair<ll,ppi>
#define B 61

int c;
vector<vector<ppi>> minIntervals(B, vector<ppi>(1)), maxIntervals(B, vector<ppi>(1));
stack<plp> minStack, maxStack;

int GetCount(vector<ppi>& intervals, int x){
  int i = lower_bound(intervals.begin(), intervals.end(), make_pair(make_pair(x + 1, 0), 0)) - intervals.begin() - 1;

  return intervals[i].second - max(0, intervals[i].first.second - x);
}

int GetCount(vector<ppi>& intervals, int l, int r){
  return GetCount(intervals, r) - GetCount(intervals, l - 1);
}

int GetCount(vector<vector<ppi>>& intervals, int k, int l, int r){
  return GetCount(intervals[k], l, r);
}

void Update(stack<plp>& S, vector<vector<ppi>>& intervals, vector<vector<ppi>>& complementIntervals, function<bool (ll, ll)> predicate, int i, ll x){
  int j = i;
  while(predicate(S.top().first, x)){
    auto [l, r] = S.top().second.first;
    int k = S.top().second.second;

    c -= GetCount(complementIntervals, k, l, r);

    j = l;
    intervals[k].pop_back();
    S.pop();
  }

  int k = __builtin_popcountll(x);
  c += GetCount(complementIntervals, k, j, i);

  int z = intervals[k].back().second;
  intervals[k].push_back({{j, i}, z + (i - j + 1)});
  S.push({x, {{j, i}, k}});
}

int Update(int i, ll x){
  Update(minStack, minIntervals, maxIntervals, [](ll a, ll b) { return a >= b; } , i, x);
  Update(maxStack, maxIntervals, minIntervals, [](ll a, ll b) { return a <= b; } , i, x);
  return c;
}

int main(){
  int n;
  scanf("%d", &n);

  c = 0;
  minStack.push({LLONG_MIN, {{0, 0}, 0}});
  maxStack.push({LLONG_MAX, {{0, 0}, 0}});

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    ans += Update(i, x);
  }

  printf("%lld\n", ans);

  return 0;
}