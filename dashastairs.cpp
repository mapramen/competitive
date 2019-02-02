#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b;

  cin >> a >> b;

  if(abs(a - b) < 2 && a + b > 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
