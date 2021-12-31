#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> GetCounts(vector<int>& B, ll x){
  int m = B.size();
  vector<int> C(m);

  while(x > 1){
    ll p = 1;
    for(int i = m - 1; i > -1; --i){
      int b = B[i] + 1;
      ll c = (x / p) + (x % p != 0);
      if(c <= b){
        C[i] = c - 1;
        x -= ((c - 1) * p);
        if(p == 1){
          x = 0;
        }
        break;
      }
      p *= b;
    }
  }

  return C;
}

string Solve(){
  ll n, k, x;
  string s;

  cin >> n >> k >> x >> s;

  string t;
  for( ; !s.empty() && s.back() == 'a'; s.pop_back()){
    t.push_back('a');
  }

  vector<int> A, B;

  reverse(s.begin(), s.end());
  while(!s.empty()){
    int a = 0, b = 0;
    for( ; !s.empty() && s.back() == 'a'; ++a, s.pop_back());
    for( ; !s.empty() && s.back() == '*'; ++b, s.pop_back());
    A.push_back(a), B.push_back(b * k);
  }

  vector<int> C = GetCounts(B, x);

  for(int i = 0, m = A.size(); i < m; ++i){
    int a = A[i], c = C[i];
    while(a--){
      s.push_back('a');
    }

    while(c--){
      s.push_back('b');
    }
  }

  return s + t;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}