#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 4

vector<string> grid;
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, 1, -1};

bool CheckDirection(int x, int y, int i){
  int k = 0;

  for( ; x > -1 && x < B && y > -1 && y < B && grid[x][y] == 'x'; x += dx[i], y += dy[i], k++);

  return (k >= 3);
}

bool CheckBoard(){
  bool ans = 0;
  for(int x = 0; x < B && ans == 0; x++)
    for(int y = 0; y < B && ans == 0; y++)
      for(int i = 0; i < B && ans == 0; i++)
        ans |= CheckDirection(x, y, i);
  return ans;
}

int main(){
  bool ans = 0;
  for(int i = 0; i < B; i++){
    string s;
    cin >> s;
    grid.PB(s);
  }

  for(int x = 0; x < B && ans == 0; x++)
    for(int y = 0; y < B && ans == 0; y++)
      if(grid[x][y] == '.'){
        grid[x][y] = 'x';
        ans |= CheckBoard();
        grid[x][y] = '.';
      }

  if(ans)
    cout << "YES\n";
  else
    cout << "NO\n";

	return 0;
}
