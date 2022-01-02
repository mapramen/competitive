#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
bool Solve(){
  int a[3];
  for(int i = 0; i < 3; ++i){
    scanf("%d", &a[i]);
  }
  sort(a, a + 3);

  return a[2] == a[0] + a[1] || (a[2] % 2 == 0 && a[0] == a[1]) || (a[0] % 2 == 0 && a[1] == a[2]);
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}