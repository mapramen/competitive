#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int &x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  return a[n - 1] + a[n - 2];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}