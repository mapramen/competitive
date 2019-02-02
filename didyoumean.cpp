#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;

  cin >> s;
  for(int i = 0, n = s.size(); i < n; ){
    set<char> m;
    for(int j = i; j < n; ++j){
      char c = s[j];
      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        for( ; i <= j; ++i)
          cout << s[i];
        m.clear();
      }
      else
        m.insert(c);

      if(m.size() > 2 || (m.size() == 2 && j - i + 1 > 2)){
        for( ; i < j; ++i)
          cout << s[i];
        cout << " ";
        break;
      }

      if(j == n - 1){
        for( ; i < n; ++i)
          cout << s[i];
        cout << "\n";
        break;
      }
    }
  }

  return 0;
}
