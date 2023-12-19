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

map<char, int> ParseMachineCategories(string& s) {
  stringstream ss(s.substr(1, s.size() - 2));
  string machine_part_string;

  map<char, int> machine_categories;
  while (getline(ss, machine_part_string, ',')) {
    char category_name = machine_part_string[0];
    int category_value = stoi(machine_part_string.substr(2));
    machine_categories[category_name] = category_value;
  }
  return machine_categories;
}

bool IsMachinePartAccepted(map<string, vector<trule>>& workflows, map<char, int>& machine_categories) {
  string workflow_name = "in";
  while (workflow_name != "R" && workflow_name != "A") {
    for (auto& rule : workflows[workflow_name]) {
      auto [category_name, oprtr, value, next_workflow_name] = rule;
      if (oprtr == '=') {
        workflow_name = next_workflow_name;
        break;
      }

      int category_value = machine_categories[category_name];
      if (oprtr == '<') {
        if (category_value < value) {
          workflow_name = next_workflow_name;
          break;
        }
        continue;
      }

      if (oprtr == '>') {
        if (category_value > value) {
          workflow_name = next_workflow_name;
          break;
        }
        continue;
      }
      assert(false);
    }
  }
  return workflow_name == "A";
}

int main() {
  map<string, vector<trule>> workflows = ReadWorkflows();

  ll ans = 0;
  while (true) {
    string s;
    if (!getline(cin, s)) {
      break;
    }

    map<char, int> machine_categories = ParseMachineCategories(s);

    if (IsMachinePartAccepted(workflows, machine_categories)) {
      for (auto [_, v] : machine_categories) {
        ans += v;
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}