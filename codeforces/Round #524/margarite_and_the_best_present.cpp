#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int Sum(int n){
  int ans = (n / 2) - (n % 2) * n;
  return ans;
}

int Sum(int l, int r){
  return Sum(r) - Sum(l - 1);
}

int main(){
  int q;

  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << Sum(l, r) << '\n';
  }

  return 0;
}
