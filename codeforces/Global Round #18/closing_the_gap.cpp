#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
int Solve(){
  int n;
  scanf("%d", &n);
 
  int s = 0;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    s += x;
  }
 
  return min(1, s % n);
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}