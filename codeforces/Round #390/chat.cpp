#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

set<char> d;

int main(){
  int t;

  d.insert('.');
  d.insert(',');
  d.insert('!');
  d.insert('?');
  d.insert(' ');

  scanf("%d", &t);

  while(t--){
    int n, m;
    vector<string> chats, texts;
    map<string, int> usernameMap;
    vector<string> usernames;
    vector< vector<int> > dp;

    scanf("%d", &n);
    getchar();

    usernames.resize(n + 1);

    for(int i = 1; i <= n; i++){
      string s;
      char c;

      while(scanf("%c", &c) && c != '\n' && c != ' ')
        s.PB(c);

      usernameMap.insert(MP(s, i));
      usernames[i] = s;
    }

    chats.PB(string(""));

    scanf("%d", &m);
    getchar();

    for(int i = 0; i < m; i++){
      string s;
      char c;

      while(scanf("%c", &c) && c != '\n')
        s.PB(c);

      chats.PB(s);
    }

    dp.resize(m + 1);
    texts.resize(m + 1);

    for(int i = 0; i <= m; i++)
      dp[i].resize(n + 1);

    for(int i = 1; i <= m; i++){
      string s = chats[i];
      int j, k;
      set<int> pusers;

      for(j = k = 0; k < s.size() && s[k] != ':'; k++);

      string user = string(s, j, k - j);
      string text = string(s, k + 1, s.size() - 1 - k);
      texts[i] = text;

      if(user != "?")
        pusers.insert(usernameMap[user]);
      else{
        for(int x = 1; x <= n; x++)
          pusers.insert(x);

        for(j = k + 1; j < s.size(); j++){
          if(d.find(s[j]) != d.end())
            continue;

          for(k = j + 1; k < s.size() && d.find(s[k]) == d.end(); k++);

          string nuser = string(s, j, k - j);

          if(usernameMap.find(nuser) != usernameMap.end())
            pusers.erase(usernameMap[nuser]);

          j = k;
        }
      }

      for(auto puser : pusers)
        dp[i][puser] = 1;
    }

    for(int i = m - 1; i > 0; i--){
      for(int j = 1; j <= n; j++){
        if(dp[i][j] == 0)
          continue;

        int k;
        for(k = 1; k <= n; k++)
          if(k != j && dp[i + 1][k] != 0)
            break;

        if(k == n + 1)
          dp[i][j] = 0;
        else
          dp[i][j] = k;
      }
    }

    int i, j;
    for(i = j = 1; j <= n && dp[i][j] == 0; j++);

    if(j == n + 1)
      cout << "Impossible\n";
    else
      for( ; i <= m; j = dp[i][j], i++)
        cout << usernames[j] << ":" << texts[i] << "\n";
  }

  return 0;
}
