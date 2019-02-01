#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, i, j, k, a, c, g, t;
  string s;
  queue<int> q;

  cin >> n >> s;

  a = c = g = t = n / 4;

  for(i = 0; i < n; i++){
    if(s[i] == '?')
      q.push(i);
    else{
      if(s[i] == 'A')
        a--;
      else if(s[i] == 'C')
        c--;
      else if(s[i] == 'G')
        g--;
      else
        t--;
    }
  }

  if(n % 4 != 0 || a < 0 || c < 0 || g < 0 || t < 0)
    s = string("===");
  else{
    while(!q.empty()){
      i = q.front();
      q.pop();

      if(a){
        s[i] = 'A';
        a--;
      }
      else if(c){
        s[i] = 'C';
        c--;
      }
      else if(g){
        s[i] = 'G';
        g--;
      }
      else{
        s[i] = 'T';
        t--;
      }
    }
  }

  cout << s << '\n';

  return 0;
}
