#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000005

int n;
ll d[N], s[N];

void AddAP(ll a, ll x, ll i, ll j){
  if(i == n)
    return ;
  s[i] += a;
  s[j + 1] -= (a + x * (j - i));
  d[i + 1] += x;
  d[j + 1] -= x;
}

int main(){
  int min_i = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int p;
    scanf("%d", &p);
    if(p < i){
      AddAP(i - p, 1, 0, n - i);
      AddAP(p - 1, -1, n - i + 1, n - i + p);
      AddAP(0, 1, n - i + p, n - 1);
    }
    else{
      AddAP(p - i, -1, 0, p - i);
      AddAP(0, 1, p - i, n - i);
      AddAP(p - 1, -1, n - i + 1, n - 1);
    }
  }

  for(ll i = 1; i < n; i++)
    d[i] += d[i - 1];

  for(ll i = 1; i < n; i++){
    s[i] += (s[i - 1] + d[i]);
    if(s[i] < s[min_i])
      min_i = i;
  }

  printf("%lld %d\n", s[min_i], min_i);

  return 0;
}
