#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

string name1[N], name2[N];

int main(){
  int n;
  bool valid = 1;
  queue<int> q;

  cin >> n;

  for(int i = 1; i <= n; i++){
    string s1, s2;
    cin >> s1 >> s2;
    name1[i] = string(s1, 0, 3);
    name2[i] = string(s1, 0, 2) + string(s2, 0, 1);
    q.push(i);
  }

  while(!q.empty() && valid == 1){
    int i = q.front();
    q.pop();

    if(name1[i].empty() && name2[i].empty()){
      valid = 0;
      continue;
    }

    if(!name1[i].empty()){
      int cnt = 0;

      for(int j = 1; j <= n; j++)
        cnt += (!name1[j].empty() && name1[j] == name1[i]);

      for(int j = 1; j <= n && cnt > 1; j++){
        if(j != i && !name1[j].empty() && name1[j] == name1[i]){
          name1[j].clear();
          q.push(j);
        }
      }

      if(cnt > 1){
        name1[i].clear();
        q.push(i);
      }

      cnt = 0;
      for(int j = 1; j <= n; j++)
        cnt += (name1[j].empty() && !name2[j].empty() && name2[j] == name1[i]);

      if(cnt > 0){
        name1[i].clear();
        q.push(i);
      }
    }
    else{
      int cnt = 0;

      for(int j = 1; j <= n; j++)
        cnt += (!name1[j].empty() && name1[j] == name2[i]);

      for(int j = 1; j <= n && cnt > 0; j++){
        if(!name1[j].empty() && name1[j] == name2[i]){
          name1[j].clear();
          q.push(j);
        }
      }

      cnt = 0;
      for(int j = 1; j <= n; j++)
        cnt += (name1[j].empty() && !name2[j].empty() && name2[j] == name2[i]);

      for(int j = 1; j <= n && cnt > 1; j++){
        if(j != i && name1[j].empty() && !name2[j].empty() && name2[j] == name2[i]){
          name2[j].clear();
          q.push(j);
        }
      }

      if(cnt > 1){
        name2[i].clear();
        q.push(i);
      }
    }
  }

  if(valid == 0)
    cout << "NO\n";
  else{
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
      if(!name1[i].empty())
        cout << name1[i] << "\n";
      else
        cout << name2[i] << "\n";
    }
  }

  return 0;
}
