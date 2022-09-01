#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<string,int> cost;
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> Q;
char s[20];

string ReadString(){
  scanf("%s", s);
  return string(s);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int t;
    scanf("%d", &t);
    string s = ReadString();

    if(t != 3){
      int x;
      scanf("%d", &x);
      cost[s] = x;
      Q.push({x, s});
      continue;
    }
    
    for( ; !Q.empty() && cost[Q.top().second] != Q.top().first; Q.pop());

    printf("%s %d\n", Q.top().second.c_str(), i);
    Q.pop();
  }

  return 0;
}