#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Print(int a, int b, int c, int d){
  printf("%d %d %d %d\n", a, b, c, d);
}

void Solve(){
  int n;
  scanf("%d", &n);

  if(n % 2 == 1){
    int m = n / 2;
    Print(m - 1, m, 1, 1);
    return;
  }

  if(n % 4 == 2){
    int m = n / 4;
    Print(2 * m - 1, 2 * m + 1, 1, 1);
    return;
  }

  return Print(n / 4, n / 4, n / 4, n / 4);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}