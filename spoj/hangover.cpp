#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ReadInput(){
  int a, b;
  scanf("%d.%d", &a, &b);
  return 100 * a + b;
}

int Solve(){
  int n = ReadInput();
  if(n == 0){
    exit(0);
  }

  long double hundred = 100, s = 0;
  int i = 0;
  while(s < n){
    ++i;
    s += (hundred / (i + 1));
  }
  return i;
}

int main(){
  while(true){
    printf("%d card(s)\n", Solve());
  }
  return 0;
}