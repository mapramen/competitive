#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

string ans[N];
vector< string > names;

void Initialise(){
  for(int i = 1; i < N; i++){
    int x = i / 26, y = i % 26 + 1;
    string s;

    if(y)
      s.PB('A' + y - 1);

    if(x)
      s.PB('a' + x - 1);

    names.PB(s);
  }
}

int main(){
  int n, k;

  Initialise();

  cin >> n >> k;

  for(int x = 1; x <= n - k + 1; x++){
    if(ans[x].size() == 0){
      set< string > availNames;
      for(auto name : names)
        availNames.insert(name);

      for(int y = x - 1, i = 1; y > 0 && i < k; y--, i++)
        availNames.erase(ans[y]);

      for(int y = x + 1, i = 1; i < k; y++, i++)
        availNames.erase(ans[y]);

      ans[x] = *availNames.begin();
    }

    string s;
    cin >> s;
    if(s == "NO")
      ans[x + k - 1] = ans[x];
    else{
      set< string > availNames;
      for(auto name : names)
        availNames.insert(name);
      for(int y = x, i = 0; i < k; y++, i++){
        if(ans[y].size() != 0)
          availNames.erase(ans[y]);
      }

      for(int y = x, i = 0; i < k; y++, i++){
        if(ans[y].size() == 0)
          ans[y] = *availNames.begin();
        availNames.erase(ans[y]);
      }
    }
  }

  for(int i = 1; i <= n; i++)
    if(ans[i].size() == 0)
      ans[i] = names[0];

  for(int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}
