#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 7000
#define B 2

vector<int> s[B];
int loseCnt[B * N];
bool win[B * N], lose[B * N];

int main(){
  int n;
  cin >> n;
  queue<int> q;

  for(int x = 0; x < B; x++){
    int k;
    cin >> k;
    while(k--){
      int i;
      cin >> i;
      s[x].PB(i);
    }
    sort(s[x].begin(), s[x].end());
  }

  for(int i = 0; i < 2; i++){
    lose[i] = 1;
    q.push(i);
  }

  while(!q.empty()){
    int x = q.front();
    q.pop();

    int i = x / B, j = x % B;

    if(lose[x]){
      for(auto k : s[1 - j]){
        int y = 2 * ((i + n - k) % n) + (1 - j);

        if(win[y] == 0){
          win[y] = 1;
          q.push(y);
        }
      }
    }
    else{
      for(auto k : s[1 - j]){
        int y = 2 * ((i + n - k) % n) + (1 - j);
        loseCnt[y]++;

        if(loseCnt[y] == s[1 - j].size()){
          lose[y] = 1;
          q.push(y);
        }
      }
    }
  }

  for(int j = 0; j < B; j++){
    for(int i = 1; i < n; i++){
      int x = 2 * i + j;
      if(win[x])
        cout << "Win ";
      else if(lose[x])
        cout << "Lose ";
      else
        cout << "Loop ";
    }
    cout << "\n";
  }

  return 0;
}
