#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<int>& a, int c, int m){
  for(int n = a.size(), i = 0; i < n && c > 0; ){
    --c;
    int x = a[i];
    for( ; i < n && a[i] - x < m; ++i);
  }
  return c <= 0;
}

int BinarySearch(vector<int>& a, int c){
  int l = 0, r = (a.back() - a.front()) / (c - 1), ans = 0;
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(Check(a, c, mid)){
      ans = mid, l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }
  return ans;
}

int Solve(){
  int n, c;
  scanf("%d%d", &n, &c);

  vector<int> a(n);
  for(int &ai: a){
    scanf("%d", &ai);
  }
  sort(a.begin(), a.end());

  return BinarySearch(a, c);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}