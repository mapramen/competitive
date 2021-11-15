#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[N];

ll Solve(){
  int n, t, m;
  ll ans = 0;

  scanf("%d%s", &n, s);

  t = 0;
  for(int i = 0; i < n; ++i){
    t += (s[i] == '#');
  }

  m = 0;
  for( ; m < n && s[m] == '#'; ++m);

  for(int i = m; i < n; ++i){
    for( ; i < n && s[i] == '.'; ++i);
    if(i == n){
      break;
    }

    int x = 1, y = 1;
    vector<int> A;
    A.PB(i);
    for(++i; i < n && x <= y; ++i){
      if(s[i] == '.'){
        ++x;
      }
      else{
        ++y;
        A.PB(i);
      }
    }

    if(x <= y){
      break;
    }

    for(int j = i - 2; A.size() > 0; j -= 2){
      int k = A.back();
      A.pop_back();
      ans += (j - k + j - (m + A.size()));
    }

    m += y;
    --i;
  }

  if(m != t){
    ans = -1;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}
