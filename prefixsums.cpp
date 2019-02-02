#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<ll> a;

bool PreliminaryCheck(ll k){
  int n = a.size();
  bool check = 0;
  for(auto x : a)
    check |= (x >= k);
  return check;
}

bool Check(ll m, ll k){
  int n = a.size();
  k -= a[n - 1];
  k -= m * a[n - 2];
  if(k <= 0)
    return 1;
  else{
    if(n == 2)
      return 0;
    else
      return (m * (m + 1)) / 2 >= k / a[0];
  }
}

ll BinarySearch(ll k){
  ll x = 1, y, z;
  if(a.size() == 2)
    y = (k + a[0] - 1) / a[0];
  else
    y = sqrt(2 * k) + 1;
  z = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid, k))
      y = mid - 1, z = mid;
    else
      x = mid + 1;
  }
  return z;
}

ll LinearSearch(ll k){
  ll n = a.size(), c = -1;
  bool check = 0;
  while(!check){
    for(auto x : a)
      check |= (x >= k);
    for(int i = 1; i < n; ++i)
      a[i] += a[i - 1];
    ++c;
  }
  return c;
}

int main(){
  int n;
  ll k;
  queue<int> q;

  scanf("%d%lld", &n, &k);
  while(n--){
    int x;
    scanf("%d", &x);
    q.push(x);
  }

  while(q.front() == 0)
    q.pop();

  while(!q.empty()){
    a.PB(q.front());
    q.pop();
  }

  n = a.size();

  if(PreliminaryCheck(k))
    printf("0\n");
  else{
    if(n < 4)
      printf("%lld\n", BinarySearch(k));
    else
      printf("%lld\n", LinearSearch(k));
  }

  return 0;
}
