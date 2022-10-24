#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  vector<int> b;
  for(int i = 0; i < m; ++i){
    b.push_back((n - 1 + a[(i + 1) % m] - a[i]) % n);
  }
  sort(b.begin(), b.end(), greater<int>());

  int ans = 0;
  for(int i = 0, c = 0; i < m; ++i){
    int x = max(0ll, b[i] - 2ll * c);
    if(x == 0){
      break;
    }
    if(x < 3){
      ans += 1, ++c;
    }
    else{
      ans += (x - 1), c += 2;
    }
  }

  return n - ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}