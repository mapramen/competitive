#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 60

ll c[B];
vector<ll> v, r;

bool Check(){
  bool check = (r.size() <= v.size());
  for(int i = 0; i < r.size() && check == 1; i++)
    check = (r[i] <= (1ll << (v[i] + 1)));
  return check;
}

int main(){
  int n, m;
  vector<int> ans;

  scanf("%d", &n);
  m = n;
  while(n--){
    ll x;
    scanf("%lld", &x);
    if((x & (x - 1)) == 0){
      int k = __builtin_popcountll(x - 1);
      c[k]++;
    }
    else
      r.PB(x);
  }

  for(int i = B - 1; i > -1; ){
    if(c[i] == 0){
      i--;
      continue;
    }
    int j = 0;
    for( ; j < i && c[j] > 0; j++);
    if(j == i){
      for(j = 0; j <= i; j++)
        c[j]--;
      v.PB(i);
    }
    else{
      while(c[i]){
        r.PB((1ll << i));
        c[i]--;
      }
    }
  }

  sort(r.begin(), r.end(), greater<ll>());
  
  if(Check()){
    n = v.size();
    ans.PB(n);
    reverse(v.begin(), v.end());
    for(int x = 0; x < v.size(); x++){
      for(int i = 0; i <= v[x]; i++)
        r.PB((1ll << i));
      if(r.size() <= n - x - 1)
        ans.PB(n - x - 1);
      else
        break;
    }
  }

  sort(ans.begin(), ans.end());

  if(ans.size() == 0)
    printf("-1\n");
  else{
    for(auto x : ans)
      printf("%d ", x);
    printf("\n");
  }

  return 0;
}
