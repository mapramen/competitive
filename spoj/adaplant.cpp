#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Compute(vector<int>& A, int k){
  int ans = 0;

  deque<int> Q;
  for(int n = A.size(), i = 0; i != n; ++i){
    while(!Q.empty() && A[Q.back()] >= A[i]){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() >= k){
      Q.pop_front();
    }

    Q.push_back(i);
    ans = max(ans, A[Q.back()] - A[Q.front()]);
  }

  return ans;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<int> b(a);
  reverse(a.begin(), a.end());
  k += 2;

  return max(Compute(a, k), Compute(b, k));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}