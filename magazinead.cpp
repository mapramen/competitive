#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> v;

bool Check(int m, int k){
  int c = 1, s = 0;
  for(auto x : v){
    if(s + x <= m)
      s += x;
    else if(x <= m){
      s = x;
      c++;
    }
    else{
      c += k;
      break;
    }
  }
  return (c <= k);
}

int BinarySearch(int k, int n){
  int x = 1, y = n, z = n;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(mid, k))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int main(){
  int n = 0, k, l = 0;
  char c;

  scanf("%d", &k);

  scanf("%c", &c);
  while(scanf("%c", &c) != EOF){
    if(c == '\n')
      break;
    l++;
    if(c == ' ' || c == '-'){
      v.PB(l);
      l = 0;
    }
  }

  if(l != 0)
    v.PB(l);

  for(auto x : v){
    n += x;
  }

  printf("%d\n", BinarySearch(k, n));

  return 0;
}
