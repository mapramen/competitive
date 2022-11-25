#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

vector<vector<int>> men_preferences(N);
int women_preference_priority[N][N], women_partner[N];
queue<int> Q;

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &i);

    for(int x = n; x > 0; --x){
      int j;
      scanf("%d", &j);
      women_preference_priority[i][j] = x;
    }

    women_partner[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &i);
    men_preferences[i].clear();

    for(int x = n; x > 0; --x){
      int j;
      scanf("%d", &j);
      men_preferences[i].push_back(j);
    }

    reverse(men_preferences[i].begin(), men_preferences[i].end());
    Q.push(i);
  }

  while(!Q.empty()){
    int i = Q.front();

    int j = men_preferences[i].back();
    men_preferences[i].pop_back();

    if(women_preference_priority[j][i] < women_preference_priority[j][women_partner[j]]){
      continue;
    }

    if(women_partner[j] != 0){
      Q.push(women_partner[j]);
    }

    women_partner[j] = i;
    Q.pop();
  }

  for(int i = 1; i <= n; ++i){
    printf("%d %d\n", women_partner[i], i);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}