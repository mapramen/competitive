#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int maxOdd = INT_MIN, maxEven = INT_MIN;
  for(int x: a){
    if(x % 2 == 1 && maxOdd > x){
      return false;
    }

    if(x % 2 == 0 && maxEven > x){
      return false;
    }

    if(x % 2 == 1){
      maxOdd = max(maxOdd, x);
    }
    else{
      maxEven = max(maxEven, x);
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