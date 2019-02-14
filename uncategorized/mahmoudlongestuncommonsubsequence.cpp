#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string a, b;

  cin >> a >> b;

  if(a != b)
    cout << max(a.size(), b.size()) << '\n';
  else
    cout << "-1\n";
    
  return 0;
}
