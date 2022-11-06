#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end(), greater<pii>());

  for(int i = 0, x = INT_MAX, y = INT_MIN; i < n; ){
    int z = a[i].first;
    for(int j = i; j < n && a[j].first == z; ++j){
      if(x < a[j].second && a[j].second < y){
        return false;
      }
    }

    for( ; i < n && a[i].first == z; ++i){
      x = min(x, a[i].second);
      y = max(y, a[i].second);
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}