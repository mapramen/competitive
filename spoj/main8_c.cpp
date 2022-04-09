#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<int>& a, int k, int m){
  ll s = 0;
  for(int x: a){
    s += (x / m);
  }
  return k <= s;
}

int BinarySearch(vector<int>&a, int k){
  int x = 1, y = *max_element(a.begin(), a.end()), ans = 0;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(a, k, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  return BinarySearch(a, k);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}