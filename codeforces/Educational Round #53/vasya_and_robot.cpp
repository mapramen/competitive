#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200005

int prefixX[N], prefixY[N], suffixX[N], suffixY[N];

int UpdateX(char c){
  if(c == 'L'){
    return -1;
  }
  if(c == 'R'){
    return 1;
  }
  return 0;
}

int UpdateY(char c){
  if(c == 'D'){
    return -1;
  }
  if(c == 'U'){
    return 1;
  }
  return 0;
}

bool Check(int n, int x, int y){
  if(abs(x) + abs(y) > n || (n - abs(x) - abs(y)) % 2 == 1){
    return 0;
  }
  return 1;
}

bool Check(int n, int x, int y, int m){
  for(int i = 0; i + m <= n; ++i){
    int tx = x - (prefixX[i] + suffixX[i + m + 1]), ty = y - (prefixY[i] + suffixY[i + m + 1]);
    if(Check(m, tx, ty)){
      return 1;
    }
  }
  return 0;
}

int BinarySearch(int n, int x, int y){
  int l = 0, r = n, ans = n;
  while(l <= r){
    int mid = l + (r - l) / 2;
    if(Check(n, x, y, mid)){
      ans = mid, r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n, x, y;
  string s;

  cin >> n >> s >> x >> y;

  if(!Check(n, x, y)){
    printf("-1\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    prefixX[i] = prefixX[i - 1] + UpdateX(s[i - 1]);
    prefixY[i] = prefixY[i - 1] + UpdateY(s[i - 1]);
  }

  for(int i = n; i > 0; --i){
    suffixX[i] = suffixX[i + 1] + UpdateX(s[i - 1]);
    suffixY[i] = suffixY[i + 1] + UpdateY(s[i - 1]);
  }

  printf("%d\n", BinarySearch(n, x, y));

  return 0;
}
