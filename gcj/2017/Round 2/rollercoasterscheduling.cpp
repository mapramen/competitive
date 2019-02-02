#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int GetLowerBound(vector< pii >& A){
  map<int,int> M;
  for(auto x : A){
    int p, b;
    tie(p, b) = x;
    ++M[b];
  }

  int ans = A.size();
  for(auto p : M)
    ans = min(ans, p.second);

  return ans;
}

int GetNumberChildren(vector< pii >& A){
  set<int> s;
  for(auto x : A){
    int p, b;
    tie(p, b) = x;
    s.insert(b);
  }
  return s.size();
}

bool Check(vector< pii >& A, int n, int c, int m){
  multiset< pii > S;

  for(auto x : A)
    S.insert(x);

  for(int j = 1; j <= m && !S.empty(); ++j){
    set<int> s;
    for(int i = 1; i <= n && !S.empty() && s.size() < c; ++i){
      for(auto it = S.lower_bound(MP(i, 0)); it != S.end(); ++it){
        int p = it->first;
        int b = it->second;
        if(p < i){
          continue;
        }
        if(s.find(b) == s.end()){
          s.insert(b);
          S.erase(it);
          break;
        }
      }
    }
  }

  return S.empty();
}

int BinarySearch(vector< pii >& A, int n, int c){
  int x = GetLowerBound(A), y = A.size(), z = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(A, n, c, mid)){
      z = mid, y = mid - 1;
    }
    else
      x = mid + 1;
  }
  return z;
}

void Solve(){
  int n, c, m;
  vector< pii > A;

  scanf("%d%d%d", &n, &c, &m);

  while(m--){
    int p, b;
    scanf("%d%d", &p, &b);
    A.PB(MP(p, b));
  }

  c = GetNumberChildren(A);

  m = BinarySearch(A, n, c);

  map< int, int > M;
  for(auto x : A){
    int p, b;
    tie(p, b) = x;
    ++M[p];
  }

  int s = 0;
  for(auto p : M){
    s += min(m, p.second);
  }

  s = A.size() - s;

  printf("%d %d\n", m, s);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }

  return 0;
}
