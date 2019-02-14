#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<string> friendNames;
vector< vector<string> > friendNumberList;

int FriendID(string s){
  int id;
  for(id = 0; id < friendNames.size() && friendNames[id] != s; ++id);
  if(id == friendNames.size()){
    friendNames.PB(s);
    friendNumberList.resize(friendNames.size());
  }
  return id;
}

void SimplifyPhoneNumbers(vector<string>& v){
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  vector<string> u;
  for(auto t : v){
    bool skip = 0;
    for(auto s : u){
      if(s.find(t) != string::npos && s.find(t) == 0)
        skip = 1;
    }
    if(skip == 0)
      u.PB(t);
  }

  v.clear();

  for(auto x : u)
    v.PB(x);
}

int main(){
  int n;

  cin >> n;
  while(n--){
    int m;
    string f;
    cin >> f;
    int i = FriendID(f);
    cin >> m;
    while(m--){
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      friendNumberList[i].PB(s);
    }
  }

  cout << friendNames.size() << '\n';
  for(int i = 0; i < friendNames.size(); ++i){
    SimplifyPhoneNumbers(friendNumberList[i]);
    cout << friendNames[i] << ' ';
    cout << friendNumberList[i].size() << ' ';
    for(auto s : friendNumberList[i]){
      reverse(s.begin(), s.end());
      cout << s << ' ';
    }
    cout << '\n';
  }

  return 0;
}
