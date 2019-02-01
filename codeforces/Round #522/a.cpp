#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 32

string InvDir(string dir){
  string invDir;
  if(dir == "u"){
    invDir = "d";
  }
  else if(dir == "d"){
    invDir = "u";
  }
  else if(dir == "l"){
    invDir = "r";
  }
  else{
    invDir = "l";
  }
  return invDir;
}

string CopyCellDir(string dir){
  string invDir = InvDir(dir);
  string ans = dir + "10" + invDir + "t" + invDir + "s" + dir + "t";
  return ans;
}

string AnsString(){
  string ans;

  string copyCellDown = CopyCellDir("d");
  string copyCellUp = CopyCellDir("u");
  string copyCellLeft = CopyCellDir("l");
  string copyCellRight = CopyCellDir("r");

  string copyRowDown = copyCellDown;
  for(int i = 1; i < B; ++i){
    copyRowDown += ("l" + copyCellDown);
  }

  for(int i = 1; i < B; ++i){
    copyRowDown += "r";
  }

  string xorCell = "1010utrtdt", carryCell = "1100utrtdt";
  string additionCell = carryCell + copyCellLeft + xorCell + copyCellRight + "l" + copyCellRight + "r";

  string additionRow = additionCell;
  for(int i = 1; i < B; ++i){
    additionRow += ("l" + additionCell);
  }

  ans = copyRowDown;
  ans += "u";
  ans += copyRowDown;
  ans += "dd";
  ans += copyRowDown;
  ans += "r0l";
  ans += additionRow;

  return ans;
}

void Print(vector< vector<int> > grid, int x, int y){
  for(int i = 4; i > -1; --i){
    for(int j = 0; j < grid[i].size(); ++j){
      if(grid[i][j] == 2){
        putchar('_');
      }
      else{
        putchar('0' + grid[i][j]);
      }
      if(i == x && j == y){
        putchar('*');
      }
      putchar(' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

int Simulate(int a, int b, string s, bool debug){
  if(debug){
    cout << a << ' ' << b << '\n';
  }

  vector< vector<int> > grid(5, vector<int>(B + 4, 2));

  for(int i = B + 1; a; --i, a /= 2){
    grid[3][i] = a % 2;
  }

  for(int i = B + 1; b; --i, b /= 2){
    grid[2][i] = b % 2;
  }

  stack< pair< vector< vector<int> >, pii > > S;
  S.push(MP(grid, MP(2, B + 1)));

  int x = 2, y = B + 1;
  string t;

  if(debug){
    cout << t << '\n';
    Print(grid, x, y);
  }

  for(auto c : s){
    if(c == 'u'){
      ++x;
    }
    else if(c == 'd'){
      --x;
    }
    else if(c == 'l'){
      --y;
    }
    else if(c == 'r'){
      ++y;
    }
    else if(c == 's'){
      //
    }
    else if(c == '0'){
      grid[x][y] = 0;
    }
    else if(c == '1'){
      grid[x][y] = 1;
    }
    else if(c == 'e'){
      grid[x][y] = 2;
    }
    else{
      if(grid[x][y] != 2){
        int d = 1 + grid[x][y];

        while(d--){
          S.pop();
        }

        grid = S.top().first;
        tie(x, y) = S.top().second;

        S.pop();
      }
    }

    S.push(MP(grid, MP(x, y)));

    t.PB(c);

    if(debug){
      cout << t << '\n';
      Print(grid, x, y);
    }
  }

  int ans = 0;
  for( ; y < grid[x].size() && grid[x][y] != 2; ++y){
    ans = 2 * ans + grid[x][y];
  }

  return ans;
}

void StressTest(){
  srand(0);
  int mx = (1 << (B - 1));
  string ans = AnsString();
  while(true){
    int a = 123456789, b = 987654321;
    int c = Simulate(a, b, ans, 0);
    if(c != a + b){
      printf("%d\n", c);
      // Simulate(a, b, ans, 1);
      break;
    }
  }
}

int main(){
  StressTest();
  return 0;
}
