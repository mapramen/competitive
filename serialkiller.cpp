#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string a, b;
  int n;

  cin >> a >> b;
  cin >> n;

  cout << a << ' ' << b << '\n';
  while(n--){
    string s, t;
    cin >> s >> t;
    if(s == a)
      a = t;
    else
      b = t;
    cout << a << ' ' << b << '\n';
  }
  
  return 0;
}
