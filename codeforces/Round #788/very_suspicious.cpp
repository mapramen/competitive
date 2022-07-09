#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int n, int m){
  int a = m / 3, b = m / 3 + (m % 3 != 0), c = (m / 3) + (m % 3 == 2);
  return n <= 2ll * a * b + 2ll * b * c + 2ll * c * a;
}

int BinarySearch(int n){
  int x = 0, y = 2 * n, ans = y;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);
  return BinarySearch(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}