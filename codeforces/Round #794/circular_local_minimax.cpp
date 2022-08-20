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

  vector<int> b(n);

  int k = 0;
  for(int i = 0; i < n; i += 2){
    b[i] = a[k++];
  }

  for(int i = 1; i < n; i += 2){
    b[i] = a[k++];
  }

  for(int i = 0; i < n; i += 2){
    int x = (n + i - 1) % n, y = (i + 1) % n;
    if((i % 2 == 0 && (b[x] <= b[i] || b[i] >= b[y])) || (i % 2 == 1 && (b[x] >= b[i] || b[i] <= b[y]))){
      printf("NO\n");
      return;
    }
  }

  printf("YES\n");
  for(int& x: b){
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