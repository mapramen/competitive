#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetCount(int t, int r){
  t /= r;

  int c = 0;
  while(c + 1 <= t){
    ++c;
    t -= c;
  }

  return c;
}

bool Check(int t, int n, vector<int>& a){
  for(int r: a){
    n -= GetCount(t, r);
  }
  return n <= 0;
}

int BinarySearch(int n, vector<int>& a){
  int x = 0, y = *min_element(a.begin(), a.end()) * n * (n + 1) / 2, ans = y;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid, n, a)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(m);
  for(int& r: a){
    scanf("%d", &r);
  }

  return BinarySearch(n, a);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}