#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int a[N];

string Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int x = 0, c = 0;
  for(int i = 1; i <= n; ++i){
    if(c == 0){
      x = a[i];
    }
    c += (x == a[i] ? 1 : -1);
  }

  c = 0;
  for(int i = 1; i <= n; ++i){
    c += (x == a[i]);
  }

  return 2 * c > n ? "YES " + to_string(x) : "NO";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}