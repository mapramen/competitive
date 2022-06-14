#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n), b(n), c(n + 1);

  for(int& x: a){
    scanf("%d", &x);
  }

  for(int& x: b){
    scanf("%d", &x);
  }

  int i = 0, j = 0;

  while(i != n && j != n){
    if(a[i] != b[j] || (i != n - 1 && a[i] == a[i + 1])){
      ++c[a[i]], ++i;
      continue;
    }

    if(c[b[j]] != 0){
      --c[b[j]];
    }
    else{
      ++i;
    }

    ++j;
  }

  return j == n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}