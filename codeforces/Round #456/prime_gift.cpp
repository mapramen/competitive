#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100

vector<int> a, b;
vector<ll> A, B;
ll inf = 1E18;

void TakeInputs(){
  vector<int> v;
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    v.PB(x);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); ++i)
    if(i % 2 == 0)
      a.PB(v[i]);
    else
      b.PB(v[i]);
}

void FillNumbers(vector<int>& a, vector<ll>& A){
  queue<ll> Q;
  queue<int> P;
  Q.push(1);
  P.push(1);
  while(!Q.empty()){
    ll x = Q.front();
    int i = P.front();

    Q.pop();
    P.pop();

    A.PB(x);

    for(auto p : a){
      if(p >= i && x <= inf / p){
        Q.push(p * x);
        P.push(p);
      }
    }
  }
  sort(A.begin(), A.end());
}

void PreProcess(){
  FillNumbers(a, A);
  FillNumbers(b, B);
}

ll GetCount(ll x){
  ll ans = 0;
  for(int n = A.size(), m = B.size(), i = 0, j = m - 1; i < n && A[i] <= x && j >= 0; ++i){
    for( ; j > -1 && x / B[j] < A[i]; --j);
    ans += (j + 1);
  }
  return ans;
}

ll BinarySearch(ll k){
  ll x = 1, y = inf, z = 1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(GetCount(mid) >= k)
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  ll k;

  TakeInputs();
  PreProcess();

  cin >> k;
  cout << BinarySearch(k) << '\n';

  return 0;
}
