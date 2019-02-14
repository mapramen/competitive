#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10
#define M 5

vector<string> s;

int GetLength(int x, int y, int dx, int dy){
  int len = 0;
  for(x += dx, y += dy; x >= 0 && y >= 0 && x < N && y < N && s[x][y] == 'X'; x += dx, y += dy, len++);
  return len;
}

int main(){
  bool ans = 0;
  for(int i = 0; i < N; i++){
    string sx;
    cin >> sx;
    s.PB(sx);
  }

  for(int x = 0; x < N; x++){
    for(int y = 0; y < N; y++){
      if(s[x][y] == 'O')
        continue;

      ans |= (GetLength(x, y, -1, 0) + GetLength(x, y, 1, 0) + 1 >= 5);
      ans |= (GetLength(x, y, 0, -1) + GetLength(x, y, 0, 1) + 1 >= 5);
      ans |= (GetLength(x, y, -1, -1) + GetLength(x, y, 1, 1) + 1 >= 5);
      ans |= (GetLength(x, y, -1, 1) + GetLength(x, y, 1, -1) + 1 >= 5);
    }
  }

  if(ans)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
