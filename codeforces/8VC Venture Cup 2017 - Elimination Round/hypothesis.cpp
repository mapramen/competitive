#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool IsPrime(int n){
  bool isPrime = 1;
  for(int i = 2; i * i <= n && isPrime; i++)
    isPrime &= (n % i != 0);
  return isPrime;
}

int Solve(int n){
  int ans = 1;
  for( ; IsPrime(n * ans + 1) == 1; ans++);
  return ans;
}

int main(){
  int n;

  cin >> n;
  cout << Solve(n) << '\n';

  return 0;
}
