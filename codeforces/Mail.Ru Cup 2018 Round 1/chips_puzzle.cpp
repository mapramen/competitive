#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 301

int d[N][3];
vector< tiiii > ans;
string T[N][N];

void ReverseString(string &s){
  reverse(s.begin(), s.end());
}

void PushToAns(int x1, int y1, int x2, int y2, char c = '\0'){
  if(c != '\0' && x2 != 1){
    T[x2][y2].PB(c);
  }
  ans.PB(MT(x1, y1, x2, y2));
}

int main(){
  int n, m;

  cin >> n >> m;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> T[i][j];
    }
    ReverseString(T[i][1]);
    ReverseString(T[i][2]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 3; j <= m; ++j){
      for(string &s = T[i][j]; !s.empty(); s.pop_back()){
        PushToAns(i, j, i, 1 + s.back() - '0', s.back());
      }
    }

    for(int x = 1; x <= 2; ++x){
      for(int j = 1; j <= 2; ++j){
        string &s = T[i][j];
        ReverseString(s);
        for( ; !s.empty(); s.pop_back()){
          int nj = (s.back() == '0') ? 1 : 2;
          int ni = (1 + s.back() - '0' == j) ? ((i == 1) ? n : 1) : i;
          PushToAns(i, j, ni, nj, s.back());
        }
        ReverseString(s);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> T[i][j];
      for(auto c : T[i][j]){
        int k = 1 + c - '0';
        d[i][k] += (k != j);
      }
    }
  }

  for(int j = 1; j <= 2; ++j){
    for(string &s = T[1][j]; !s.empty(); s.pop_back()){
      char c = s.back();
      if(1 + c - '0' == j){
        PushToAns(1, j, n, j);
        PushToAns(n, j, 1, j);
      }
      else{
        PushToAns(1, (j == 1) ? 2 : 1, 1, j);
      }
    }
  }

  for(int j = 3; j <= m; ++j){
    for(string &s = T[1][j]; !s.empty(); s.pop_back()){
      PushToAns(1, 1 + s.back() - '0', 1, j);
    }
  }

  for(int i = 2; i <= n; ++i){
    for(int j = 1; j <= 2; ++j){
      int k = d[i][j];
      while(k--){
        PushToAns(1, j, i, j);
      }
    }

    for(int j = 1; j <= m; ++j){
      for(string &s = T[i][j]; !s.empty(); s.pop_back()){
        char c = s.back();
        int nj = 1 + c - '0';
        int ni = (nj == j) ? 1 : i;
        PushToAns(ni, nj, i, j);
      }
    }
  }

  printf("%lu\n", ans.size());
  for(auto t : ans){
    int x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = t;
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }

  return 0;
}
