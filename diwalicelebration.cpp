#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  cin >> t;
  while(t--){
    int a, k, n;
    cin >> a >> k >> n;
    cout << a + (n - 1) * k << '\n';
  }

  return 0;
}
