#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3

char s[B][B + 1];

void Read(){
  for(int x = 0; x < B; ++x){
    scanf("%s", s[x]);
  }
}

int GetCount(char c){
  int ans = 0;
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      ans += (s[x][y] == c);
    }
  }
  return ans;
}

bool DidWinHorizontal(char c){
  for(int x = 0; x < B; ++x){
    bool win = true;
    for(int y = 0; y < B && win; ++y){
      win = s[x][y] == c;
    }
    if(win){
      return true;
    }
  }
  return false;
}

bool DidWinVertical(char c){
  for(int y = 0; y < B; ++y){
    bool win = true;
    for(int x = 0; x < B && win; ++x){
      win = s[x][y] == c;
    }
    if(win){
      return true;
    }
  }
  return false;
}

bool DidWinDiagonal(char c){
  bool win = true;
  for(int x = 0, y = 0; x < B && win; ++x, ++y){
    win = s[x][y] == c;
  }
  return win;
}

bool DidWinAntiDiagonal(char c){
  bool win = true;
  for(int x = 0, y = B - 1; x < B && win; ++x, --y){
    win = s[x][y] == c;
  }
  return win;
}

bool DidWin(char c){
  return DidWinHorizontal(c) || DidWinVertical(c) || DidWinDiagonal(c) || DidWinAntiDiagonal(c);
}

bool Solve(){
  Read();
  
  int z = GetCount('X') - GetCount('O');
  
  if(z < 0 || z > 1){
    return false;
  }

  if(DidWin('X')){
    return z == 1 && !DidWin('O');
  }

  if(DidWin('O')){
    return z == 0;
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "yes" : "no");
  }
  return 0;
}