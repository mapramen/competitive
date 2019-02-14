#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int BinaryPower(int n){
  int l = 0;
  while(n > 1){
    ++l;
    n /= 2;
  }
  return l;
}

int main(){
  int n, m;

  cin >> n >> m;

  if(n > BinaryPower(m))
    cout << m << '\n';
  else
    cout << m % (1 << n) << '\n';

  return 0;
}
