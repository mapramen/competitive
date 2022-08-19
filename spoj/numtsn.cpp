#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 52
#define M 18
#define MOD 1000000007

int dp_less[N][M][M][M], dp_equal[N][M][M][M];

vector<int> ReadNumber(){
  string s;
  cin >> s;

  int n = s.size();
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    v[i] = s[i] - '0';
  }

  return v;
}

void UpdateDP(int i, int x, int y, int z, int k, int d){
  int nx = x + (d == 3), ny = y + (d == 6), nz = z + (d == 9);
  if(nx >= M || ny >= M || nz >= M){
    return;
  }

  dp_less[i + 1][nx][ny][nz] = (dp_less[i + 1][nx][ny][nz] + dp_less[i][x][y][z]) % MOD;

  if(d < k){
    dp_less[i + 1][nx][ny][nz] = (dp_less[i + 1][nx][ny][nz] + dp_equal[i][x][y][z]) % MOD;
  }

  if(d == k){
    dp_equal[i + 1][nx][ny][nz] = (dp_equal[i + 1][nx][ny][nz] + dp_equal[i][x][y][z]) % MOD;
  }
}

void Calculate(vector<int> v){
  int n = v.size();

  for(int i = 0; i <= n; ++i){
    for(int x = 0; x < M; ++x){
      for(int y = 0; y < M; ++y){
        for(int z = 0; z < M; ++z){
          dp_less[i][x][y][z] = 0, dp_equal[i][x][y][z] = 0;
        }
      }
    }
  }

  dp_equal[0][0][0][0] = 1;
  for(int i = 0; i < n; ++i){
    for(int x = 0; x < M && x <= i; ++x){
      for(int y = 0; y < M && x + y <= i; ++y){
        for(int z = 0; z < M && x + y + z <= i; ++z){
          if(dp_less[i][x][y][z] == 0 && dp_equal[i][x][y][z] == 0){
            continue;
          }
          
          int k = v[i];
          dp_less[i + 1][x][y][z] = (dp_less[i + 1][x][y][z] + 7ll * dp_less[i][x][y][z] + 1ll * (k - (max(0, k - 1) / 3)) * dp_equal[i][x][y][z]) % MOD;

          UpdateDP(i, x, y, z, k, 3);
          UpdateDP(i, x, y, z, k, 6);
          UpdateDP(i, x, y, z, k, 9);

          if(k == 0 || k % 3 != 0){
            dp_equal[i + 1][x][y][z] = (dp_equal[i + 1][x][y][z] + dp_equal[i][x][y][z]) % MOD;
          }
        }
      }
    }
  }
}

int GetCountL(vector<int> v){
  Calculate(v);

  int ans = 0;
  for(int n = v.size(), x = 1; x < M; ++x){
    ans = (ans + dp_less[n][x][x][x]) % MOD;
  }

  return ans;
}

int GetCountLE(vector<int> v){
  Calculate(v);

  int ans = 0;
  for(int n = v.size(), x = 1; x < M; ++x){
    ans = (ans + dp_less[n][x][x][x]) % MOD;
    ans = (ans + dp_equal[n][x][x][x]) % MOD;
  }

  return ans;
}

int GetCount(vector<int> a, vector<int> b){
  return (MOD + GetCountLE(b) - GetCountL(a)) % MOD;
}

int Solve(){
  vector<int> a = ReadNumber();
  vector<int> b = ReadNumber();
  return GetCount(a, b);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}