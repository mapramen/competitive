#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  if(a == -1){
    exit(0);
  }

  if(a > b){
    swap(a, b);
  }

  ++a;

  return (b / a) + (b % a != 0);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}