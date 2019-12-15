#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define tiii tuple< int, int, int >
#define N 201

string A, B;
int n, m, s;
bool visited[N][N][N], parent[N][N][N], moveA[N][N][N], moveB[N][N][N];
queue< tiii > Q;
const vector<char> moves{'(', ')'};

int main(){
  cin >> A >> B;
  n = A.size(), m = B.size();
  s = max(n, m);

  visited[0][0][0] = true;
  Q.push(make_tuple(0, 0, 0));

  while(!Q.empty() && !visited[n][m][0]){
    int i, j, k;
    tie(i, j, k) = Q.front();
    Q.pop();

    char c = '(' + parent[i][j][k];

    for(char c : moves){
      int ni = i == n ? n : (i + (A[i] == c));
      int nj = j == m ? m : (j + (B[j] == c));
      int nk = k + (c == '(' ? 1 : -1);

      if(nk < 0 || nk > s || visited[ni][nj][nk]){
        continue;
      }

      visited[ni][nj][nk] = true;
      parent[ni][nj][nk] = (c != '(');
      moveA[ni][nj][nk] = (ni != i);
      moveB[ni][nj][nk] = (nj != j);

      Q.push(make_tuple(ni, nj, nk));
    }
  }

  string ans;
  for(int i = n, j = m, k = 0; i > 0 || j > 0 || k > 0; ){
    char c = '(' + parent[i][j][k];
    int ni = i - moveA[i][j][k];
    int nj = j - moveB[i][j][k];
    int nk = k - (parent[i][j][k] ? -1 : 1);

    ans.push_back(c);
    i = ni, j = nj, k = nk;
  }

  reverse(ans.begin(), ans.end());

  cout << ans << '\n';

  return 0;
}