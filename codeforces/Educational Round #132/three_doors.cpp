#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3

int a[B + 1];

bool Solve(){
  int x;
  scanf("%d", &x);

  for(int i = 1; i <= B; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = x; a[i] != 0; ){
    int j = a[i];
    a[i] = 0;
    i = j;
  }

  for(int i = 1; i <= B; ++i){
    if(a[i] != 0){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}