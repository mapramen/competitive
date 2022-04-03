#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Calculate(vector<int> a, int d, int x){
  for(int n = a.size(), i = 0; i < n; ++i){
    if(a[i] == x){
      swap(a[n - 1], a[i]);
      a.pop_back();
      break;
    }
  }
  sort(a.begin(), a.end());

  int ans = max(a.front() != 1 ? a.front() / 2 : INT_MIN, d - a.back());
  for(int i = 1; i < a.size(); ++i){
    ans = max(ans, (a[i] - a[i - 1]) / 2);
  }

  ans = min(ans, a.front());
  for(int i = 1; i < a.size(); ++i){
    ans = min(ans, a[i] - a[i - 1]);
  }

  return ans - 1;
}

int Solve(){
  int n, d;
  scanf("%d%d", &n, &d);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int ans = INT_MAX, x, y;
  for(int i = 1; i < a.size(); ++i){
    int ansx = a[i] - a[i - 1];
    if(ansx <= ans){
      ans = ansx, x = a[i - 1], y = a[i];
    }
  }

  return max(Calculate(a, d, a.front()), max(Calculate(a, d, x), Calculate(a, d, y)));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}