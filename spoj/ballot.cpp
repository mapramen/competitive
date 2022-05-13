#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(int m, int s, vector<int>& a){
  ll cnt = 0;
  for(int& x: a){
    cnt += (x / s + (x % s != 0));
  }
  return cnt <= m;
}

int BinarySearch(int m, vector<int>& a){
  int x = 1, y = *max_element(a.begin(), a.end()), ans = y;

  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(m, mid, a)){
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

  if(n == -1){
    exit(0);
  }

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  return BinarySearch(m, a);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}