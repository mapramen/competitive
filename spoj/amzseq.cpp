#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  return 0;
}

int main(){
  int n;
  scanf("%d", &n);

  int a = 1, b = 3;
  for(int i = 2; i <= n; ++i){
    int c = 2 * b + a;
    a = b;
    b = c;
  }

  printf("%d\n", b);
  
  return 0;
}