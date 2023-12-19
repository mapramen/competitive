#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define trule tuple<char, char, int, string>

string ExtractWorkflowName(string& s) {
  reverse(s.begin(), s.end());

  string workflow_name;
  while (!s.empty() && s.back() != '{') {
    workflow_name.push_back(s.back());
    s.pop_back();
  }

  s.pop_back();

  reverse(s.begin(), s.end());
  s.pop_back();

  return workflow_name;
}

trule ParseRule(string& s) {
  int colon_location = s.find(':');
  if (colon_location == string::npos) {
    return {'=', '=', 0, s};
  }

  return {s[0], s[1], stoi(s.substr(2, colon_location - 2)), s.substr(colon_location + 1)};
}

vector<trule> ParseRules(string& s) {
  stringstream ss(s);
  string rule_string;

  vector<trule> rules;
  while (getline(ss, rule_string, ',')) {
    rules.push_back(ParseRule(rule_string));
  }
  return rules;
}

map<string, vector<trule>> ReadWorkflows() {
  map<string, vector<trule>> workflows;
  while (true) {
    string s;
    getline(cin, s);

    if (s.empty()) {
      break;
    }

    string workflow_name = ExtractWorkflowName(s);
    workflows[workflow_name] = ParseRules(s);
  }
  return workflows;
}

ll GetAcceptedCount(map<string, vector<trule>>& workflows, string workflow_name, map<char, pii> machine_category_ranges) {
  if (workflow_name == "R") {
    return 0;
  }

  if (workflow_name == "A") {
    ll ans = 1;
    for (auto& [_, range] : machine_category_ranges) {
      auto [l, r] = range;
      ans *= max(0, r - l + 1);
    }
    return ans;
  }

  ll ans = 0;
  for (auto& rule : workflows[workflow_name]) {
    auto [category, oprtr, value, next_workflow_name] = rule;
    if (oprtr == '=') {
      ans += GetAcceptedCount(workflows, next_workflow_name, machine_category_ranges);
      break;
    }

    auto [l, r] = machine_category_ranges[category];
    if (oprtr == '<') {
      if (r < value) {
        ans += GetAcceptedCount(workflows, next_workflow_name, machine_category_ranges);
        break;
      }

      if (l < value) {
        machine_category_ranges[category] = {l, value - 1};
        ans += GetAcceptedCount(workflows, next_workflow_name, machine_category_ranges);
        machine_category_ranges[category] = {value, r};
      }

      continue;
    }

    if (oprtr == '>') {
      if (l > value) {
        ans += GetAcceptedCount(workflows, next_workflow_name, machine_category_ranges);
        break;
      }

      if (r > value) {
        machine_category_ranges[category] = {value + 1, r};
        ans += GetAcceptedCount(workflows, next_workflow_name, machine_category_ranges);
        machine_category_ranges[category] = {l, value};
      }

      continue;
    }

    assert(false);
  }

  return ans;
}

int main() {
  map<string, vector<trule>> workflows = ReadWorkflows();

  map<char, pii> machine_category_ranges{
      {'x', {1, 4000}},
      {'m', {1, 4000}},
      {'a', {1, 4000}},
      {'s', {1, 4000}},
  };

  ll ans = GetAcceptedCount(workflows, "in", machine_category_ranges);

  printf("%lld\n", ans);

  return 0;
}