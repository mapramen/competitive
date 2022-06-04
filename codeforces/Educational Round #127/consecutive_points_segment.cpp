#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<int>& a, int x){
  for(int& y: a){
    if(abs(y - x) > 1){
      return false;
    }
    ++x;
  }
  return true;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int x = a.front();
  return Check(a, x - 1) || Check(a, x) || Check(a, x + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}