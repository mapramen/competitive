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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int minMatrixDiff = INT_MAX;
vector<string> v, ans;

void Transpose(vector<string> &v){
  int n = v.size(), m = n > 0 ? v[0].size() : 0;
  vector<string> u;

  for(int y = 0; y < m; ++y){
    string s;
    for(int x = 0; x < n; ++x){
      s.push_back(v[x][y]);
    }
    u.push_back(s);
  }

  v.clear();

  for(string ux : u){
    v.push_back(ux);
  }
}

string AlternateString(int n, char a, char b){
  string s;
  for(int i = 0; i < n; ++i, swap(a, b)){
    s.push_back(a);
  }
  return s;
}

int Diff(string &s, string &t){
  int ans = 0;
  for(int i = 0; i < s.size(); ++i){
    ans += (s[i] != t[i]);
  }
  return ans;
}

void CheckAndUpdate(string s, bool transpose){
  int n = v.size(), m = n > 0 ? v[0].size() : 0;
  int matrixDiff = 0;
  vector<string> u;

  for(int x = 0; x < n; ++x){
    char a = s[2 * (x % 2 != 0)];
    char b = s[1 + 2 * (x % 2 != 0)];
    int minRowDiff = INT_MAX;
    string ux;
    for(int k = 0; k < 2; ++k, swap(a, b)){
      string t = AlternateString(m, a, b);
      int rowDiff = Diff(t, v[x]);
      if(rowDiff < minRowDiff){
        minRowDiff = rowDiff;
        ux = t;
      }
    }
    matrixDiff += minRowDiff;
    u.push_back(ux);
  }

  if(matrixDiff < minMatrixDiff){
    minMatrixDiff = matrixDiff;
    if(transpose){
      Transpose(u);
    }
    ans = u;
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    v.push_back(s);
  }

  for(int k = 0; k < 2; ++k){
    CheckAndUpdate("ACGT", k);
    CheckAndUpdate("AGCT", k);
    CheckAndUpdate("ATCG", k);
    CheckAndUpdate("CGAT", k);
    CheckAndUpdate("CTAG", k);
    CheckAndUpdate("GTCA", k);
    Transpose(v);
  }

  for(int x = 0; x < n; ++x){
    cout << ans[x] << '\n';
  }

  return 0;
}