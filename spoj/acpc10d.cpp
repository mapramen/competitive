#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  int ansa, ansb, ansc;
  scanf("%d%d%d", &ansa, &ansb, &ansc);

  ansa = 1E9, ansc += ansb;
  while(--n){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    ansa = min(ansa, ansb), ansc = min(ansb, ansc);
    ansb = min(ansa, ansc);

    ansa += a;
    ansb = min(ansa, ansb) + b;
    ansc = min(ansb, ansc) + c;
  }

  return ansb;
}

int main(){
  for(int k = 1; ; ++k){
    printf("%d. %d\n", k, Solve());
  }
  return 0;
}