#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  return v;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a = ReadArray(n);
  vector<int> b = ReadArray(n);

  for(int i = 0; i < n; ++i){
    int x = b[i] - a[i];
    if(x < 0 || x > 1){
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