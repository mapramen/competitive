#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

const ll INF = 1E18;

vector<pii> ReadMonkeys(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }

  return a;
}

bool CheckTime(ll cnt, vector<pii>& a, ll t){
  for(pii& p: a){
    if(t < p.first){
      continue;
    }
    cnt -= (1 + (t - p.first) / p.second);
    if(cnt <= 0){
      break;
    }
  }
  return cnt <= 0;
}

ll GetMinTime(ll cnt, vector<pii>& a){
  ll x = 0, y = INF, ans = INF;
  while(x <= y){
    ll mid = (x + y) / 2;
    if(CheckTime(cnt, a, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

ll GetCount(int t, vector<pii>& a, vector<pii>& b){
  int x = 0, y = 1E9, ans = y;
  while(x <= y){
    int mid = (x + y) / 2;
    if(GetMinTime(mid, a) + GetMinTime(mid, b) >= t){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  vector<pii> a = ReadMonkeys();
  vector<pii> b = ReadMonkeys();

  int cnt = GetCount(t, a, b);

  printf("%lld\n", GetMinTime(cnt, a));

  return 0;
}