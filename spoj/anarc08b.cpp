#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> display_code_to_digit;
map<int,string> digit_to_display_code;

void Add(int digit, vector<int> display_code_bits){
  int display_code = 0;
  for(int bit: display_code_bits){
    display_code |= (1 << bit);
  }

  std::stringstream ss;
  ss << std::setw(3) << std::setfill('0') << display_code;

  digit_to_display_code[digit] = ss.str();
  display_code_to_digit[display_code] = digit;
}

void Initialize(){
  Add(0, {0, 3, 1, 2, 4, 5});
  Add(1, {3, 1});
  Add(2, {0, 3, 6, 4, 2});
  Add(3, {0, 3, 6, 1, 2});
  Add(4, {5, 6, 3, 1});
  Add(5, {0, 5, 6, 1, 2});
  Add(6, {0, 5, 4, 2, 1, 6});
  Add(7, {0, 3, 1});
  Add(8, {0, 1, 2, 3, 4, 5, 6});
  Add(9, {0, 5, 6, 3, 1});
}

string ExtractDisplayCode(string &s){
  reverse(s.begin(), s.end());

  string ans;
  while(!s.empty()){
    char c = s.back();
    s.pop_back();

    if(!isdigit(c)){
      break;
    }

    ans.push_back(c);
  }

  reverse(s.begin(), s.end());
  return ans;
}

int DisplayCode2Decimal(string s){
  int ans = 0;
  for(int i = 0; i < s.size(); i += 3){
    int display_code = stoi(string(s.begin() + i, s.begin() + i + 3));
    ans = 10 * ans + display_code_to_digit[display_code];
  }
  return ans;
}

vector<int> Int2Vec(int n){
  vector<int> v;
  for( ; n > 0; n /= 10){
    v.push_back(n % 10);
  }

  if(v.empty()){
    v.push_back(0);
  }

  reverse(v.begin(), v.end());
  return v;
}

string Decimal2DisplayCode(int n){
  string ans;
  for(int digit: Int2Vec(n)){
    ans += digit_to_display_code[digit];
  }
  return ans;
}

string Solve(){
  string s;
  cin >> s;

  if(s == "BYE"){
    exit(0);
  }

  int a = DisplayCode2Decimal(ExtractDisplayCode(s));
  int b = DisplayCode2Decimal(ExtractDisplayCode(s));
  return Decimal2DisplayCode(a) + "+" + Decimal2DisplayCode(b) + "=" + Decimal2DisplayCode(a + b);
}

int main(){
  Initialize();
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}