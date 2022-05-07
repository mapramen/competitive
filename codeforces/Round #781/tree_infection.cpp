#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int m, vector<int>& a, int t){
  if(m > t){
    return false;
  }

  int i = a.size() - 1 - (t - m);
  return a.empty() || a.back() <= t || (i >= 0 && i < a.size() && a[i] <= t);
}

int BinarySearch(int n, int m, vector<int> a){
  int x = 1, y = n, ans = n;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(m, a, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> c(n + 1);
  ++c[0];
  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    ++c[p];
  }
  sort(c.begin(), c.end(), greater<int>());

  while(c.back() == 0){
    c.pop_back();
  }

  vector<int> a;
  for(int i = 0; i < c.size(); ++i){
    for(int j = c[i]; j > 1; --j){
      a.push_back(i + j);
    }
  }
  sort(a.begin(), a.end());

  return BinarySearch(n, c.size(), a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}