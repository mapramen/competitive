#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ReadInt(int mod){
  string s;
  cin >> s;

  int ans = 0;
  for(char c: s){
    ans = (10ll * ans + (c - '0')) % mod;
  }

  return ans;
}

int main(){
  int a = ReadInt(9);
  int b = ReadInt(6);

  int ans = 1;
  while(b--){
    ans = (a * ans) % 9;
  }

  if(ans == 0){
    ans = 9;
  }

  printf("%d\n", ans);
  
  return 0;
}