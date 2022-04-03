#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

queue<int> Q;
int a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  for(int m = n; m != 0; --m){
    int x = 0;
    for( ; Q.front() != m; ++x){
      Q.push(Q.front());
      Q.pop();
    }
    a[m] = (x + 1) % m;
    Q.pop();
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
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