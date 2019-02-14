#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> GetPrimeFactors(int n){
  vector<int> primeFactors;

  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      while(n % i == 0)
        n /= i;
      primeFactors.PB(i);
    }
  }

  if(n != 1)
    primeFactors.PB(n);

  return primeFactors;
}

int EulerTotient(int n){
  int ans = n;
  vector<int> primeFactors = GetPrimeFactors(n);

  for(auto p : primeFactors)
    ans = (ans / p) * (p - 1);

  return ans;
}

int ModularExponentation(int a, int n, int m){
  ll x = a, y = 1 % m;
  while(n > 0){
    if(n % 2)
      y = (y * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return (int)y;
}

bool IsPrimitiveRoot(int a, int n){
  bool isPrimitiveRoot = true;
  int s = EulerTotient(n);
  vector<int> v = GetPrimeFactors(s);

  for(int i = 0; i < v.size(); i++)
    v[i] = s / v[i];

  for(auto k : v){
    if(ModularExponentation(a, k, n) == 1){
      isPrimitiveRoot = false;
      break;
    }
  }
  return isPrimitiveRoot;
}

int LeastPrimitiveRoot(int n){
  int ans;

  for(ans = 2; ans < n && IsPrimitiveRoot(ans, n) == false; ans++);

  return ans;
}

int main(){
  int n;

  // cin >> n;
  // cout << LeastPrimitiveRoot(n) << ' ' << EulerTotient(EulerTotient(n)) << '\n';

  cout << IsPrimitiveRoot(1000003, 1000000007) << '\n';

	return 0;
}
