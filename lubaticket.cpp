#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 7

char s[N], t[N];
int ans = 7;

bool Check(){
  int ansx = 0;
  for(int i = 0; i < 3; ++i)
    ansx += (t[i] - '0');
  for(int i = 3; i < 6; ++i)
    ansx -= (t[i] - '0');
  return (ansx == 0);
}

void UpdateAns(){
  int ansx = 0;
  for(int i = 0; i < 6; ++i)
    ansx += (s[i] != t[i]);
  ans = min(ans, ansx);
}

void Fun(int i){
  if(i == 6){
    if(Check())
      UpdateAns();
  }
  else{
    for(char c = '0'; c <= '9'; ++c){
      t[i] = c;
      Fun(i + 1);
    }
  }
}

int main(){
  cin >> s;
  Fun(0);
  cout << ans << '\n';
  return 0;
}
