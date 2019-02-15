#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000

ll n, k, p;
ll offices[N], keys[N];
pll intervals[N];

bool SimpleCheck(ll t){
  bool check = 1;
  for(int i = 1; i <= n && check == 1; i++)
    check = (abs(offices[i] - p) <= t);
  return check;
}

bool Check(ll t){
  if(SimpleCheck(t) == 0)
    return 0;

  int intervalsSatisfied = 0;
  priority_queue< ll, vector<ll>, greater<ll> > Q;

  for(int i = 1; i <= n; i++){
    ll m = offices[i];
    intervals[i] = MP(m + p - t, m + p + t);
  }

  sort(intervals + 1, intervals + n + 1);
  sort(keys + 1, keys + k + 1);

  for(int i = 1, j = 1; i <= k; i++){
    for( ; j <= n && intervals[j].first <= keys[i]; j++)
      Q.push(intervals[j].second);
    while(!Q.empty() && Q.top() < keys[i])
      Q.pop();
    if(!Q.empty()){
      intervalsSatisfied++;
      Q.pop();
    }
  }

  return (intervalsSatisfied == n);
}

int BinarySearch(){
  ll x = 0, y = INT_MAX, z = INT_MAX;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  cin >> n >> k >> p;

  for(int i = 1; i <= n; i++)
    cin >> offices[i];

  for(int i = 1; i <= k; i++){
    cin >> keys[i];
    keys[i] *= 2;
  }

  cout << BinarySearch() << '\n';

  return 0;
}
