#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  int n = s.size();
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    a[i] = i;
  }

  for(int i = 0; i < n; ++i){
    for(int j = i, k = 1; k < n && s[j] == 'E'; ++k, j = (j + 1) % n){
      a[(j + 1) % n] = a[i];
    }
  }

  for(int i = 0, j = 1; i < n; ++i, j = (j + 1) % n){
    if((s[i] == 'E') != (a[i] == a[j])){
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