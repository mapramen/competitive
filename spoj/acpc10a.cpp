#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  if(a == 0 && b == 0 && c == 0){
    exit(0);
  }

  if(a + c == 2 * b){
    printf("AP %d\n", c + b - a);
  }
  else{
    printf("GP %d\n", c * b / a);
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}