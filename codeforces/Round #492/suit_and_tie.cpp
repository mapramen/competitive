#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

int a[N];

int main(){
  int n;

  cin >> n;
  n *= 2;

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  int ans = 0;
  for(int i = 1; i <= n; i += 2){
    if(a[i] == 0){
      continue;
    }
    for(int j = i + 1; a[i + 1] != a[i]; ++j, swap(a[i + 1], a[j]), ++ans);
  }

  cout << ans << '\n';

  return 0;
}
