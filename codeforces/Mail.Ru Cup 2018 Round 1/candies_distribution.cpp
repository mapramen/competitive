#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int l[N], r[N], c[N];

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> l[i];
  }

  for(int i = 1; i <= n; ++i){
    cin >> r[i];
  }

  vector<int> v;
  for(int i = 1; i <= n; ++i){
    v.PB(l[i] + r[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= n; ++i){
    int j = lower_bound(v.begin(), v.end(), l[i] + r[i]) - v.begin();
    c[i] = v.size() - j;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      l[j] -= (c[i] > c[j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j < i; ++j){
      r[j] -= (c[i] > c[j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(l[i] != 0 || r[i] != 0){
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  for(int i = 1; i <= n; ++i){
    cout << c[i] << ' ';
  }
  cout << '\n';

  return 0;
}
