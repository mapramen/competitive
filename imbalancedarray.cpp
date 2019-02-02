#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int a[N];

ll GetAnsX(int i, int l, int r){
  ll ans = a[i];
  ans *= (i - l + 1);
  ans *= (r - i + 1);
  return ans;
}

ll GetMinImbalance(int n){
  stack<int> A, B;
  ll ans = 0;

  for(int i = 1; i <= n; i++){
    int j = i;
    while(!A.empty() && a[A.top()] >= a[i]){
      j = B.top();
      ans += GetAnsX(A.top(), j, i - 1);
      A.pop();
      B.pop();
    }
    A.push(i);
    B.push(j);
  }

  while(!A.empty()){
    int j = B.top();
    ans += GetAnsX(A.top(), j, n);
    A.pop();
    B.pop();
  }

  return ans;
}

ll GetMaxImbalance(int n){
  stack<int> A, B;
  ll ans = 0;

  for(int i = 1; i <= n; i++){
    int j = i;
    while(!A.empty() && a[A.top()] <= a[i]){
      j = B.top();
      ans += GetAnsX(A.top(), j, i - 1);
      A.pop();
      B.pop();
    }
    A.push(i);
    B.push(j);
  }

  while(!A.empty()){
    int j = B.top();
    ans += GetAnsX(A.top(), j, n);
    A.pop();
    B.pop();
  }

  return ans;
}

ll GetImbalance(int n){
  return GetMaxImbalance(n) - GetMinImbalance(n);
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  printf("%lld\n", GetImbalance(n));

  return 0;
}
