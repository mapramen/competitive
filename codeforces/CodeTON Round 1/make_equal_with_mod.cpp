#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  n = a.size();

  bool zero_present = false, one_present = false;
  for(int x: a){
    zero_present = zero_present || x == 0;
    one_present = one_present || x == 1;
  }

  if(zero_present && one_present){
    return false;
  }

  if(!one_present){
    return true;
  }

  for(int i = 1; i < n; ++i){
    if(a[i] == a[i - 1] + 1){
      return false;
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