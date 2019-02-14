#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

bool visited[N][N][N];

void DFS(int b, int g, int r){
  if(b < 0 || g < 0 || r < 0 || visited[b][g][r] == 1)
    return ;

  visited[b][g][r] = 1;

  DFS(b - 1, g - 1, r + 1);
  DFS(b - 1, g + 1, r - 1);
  DFS(b + 1, g - 1, r - 1);

  if(b > 1)
    DFS(b - 1, g, r);

  if(g > 1)
    DFS(b, g - 1, r);

  if(r > 1)
    DFS(b, g, r - 1);
}

void PrintColor(int b, int g, int r, char c){
  if(visited[b][g][r])
    cout << c;
}

int main(){
  int n, b, g, r;
  string s;

  cin >> n >> s;

  b = g = r = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'B')
      b++;
    else if(s[i] == 'G')
      g++;
    else
      r++;
  }

  DFS(b, g, r);

  PrintColor(1, 0, 0, 'B');
  PrintColor(0, 1, 0, 'G');
  PrintColor(0, 0, 1, 'R');
  cout << '\n';

  return 0;
}
