#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Process(string s, deque<char>& q, int n, bool rev){
  int j;
  sort(s.begin(), s.end());

  if(rev)
    j = s.size() - n;
  else
    j = 0;

  for(int i = 0; i < n; i++, j++){
    q.push_back(s[j]);
  }
}

int main(){
  int n;
  string s;
  deque<char> q1, q2;
  deque<int> q;

  cin >> s;
  n = s.size();

  Process(s, q1, (n + 1) / 2, 0);

  cin >> s;
  Process(s, q2, n - (n + 1) / 2, 1);

  for(int i = 0; i < n; i++)
    q.push_back(i);

  for(int x = 0, p = 1; x < n; x++){
    if(p == 1){
      if(q2.empty() || q1.front() < q2.back()){
        s[q.front()] = q1.front();
        q.pop_front();
        q1.pop_front();
      }
      else{
        s[q.back()] = q1.back();
        q.pop_back();
        q1.pop_back();
      }
      p = 2;
    }
    else{
      if(q1.empty() || q2.back() > q1.front()){
        s[q.front()] = q2.back();
        q.pop_front();
        q2.pop_back();
      }
      else{
        s[q.back()] = q2.front();
        q.pop_back();
        q2.pop_front();
      }
      p = 1;
    }
  }

  cout << s << '\n';

  return 0;
}
