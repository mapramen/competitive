#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int m;
  scanf("%d", &m);

  int i = 0;
  while(m--){
    int x;
    scanf("%d", &x);
    i = (i + x) % n;
  }

  return a[i];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}