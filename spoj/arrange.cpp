#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int i = upper_bound(a.begin(), a.end(), 1) - a.begin();

  sort(a.begin() + i, a.end(), greater<int>());

  if(n > 1 && a[n - 1] == 2 && a[n - 2] == 3 && (n == 2 || a[n - 3] == 1)){
    swap(a[n - 2], a[n - 1]);
  }

  for(int x: a){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}