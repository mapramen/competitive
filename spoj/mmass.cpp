#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  string s;
  cin >> s;

  stack<int> S;
  for(char c: s){
    if(isdigit(c)){
      S.top() *= (c - '0');
    }
    
    if(c == '('){
      S.push(0);
    }

    if(c == 'C'){
      S.push(12);
    }

    if(c == 'O'){
      S.push(16);
    }

    if(c == 'H'){
      S.push(1);
    }

    if(c != ')'){
      continue;
    }

    int x = 0;
    while(S.top() != 0){
      x += S.top();
      S.pop();
    }
    S.pop();

    S.push(x);
  }

  int ans = 0;
  for( ; !S.empty(); S.pop()){
    ans += S.top();
  }

  printf("%d\n", ans);
  
  return 0;
}