#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tmodule tuple<char, vector<string>, vector<string>>
#define MAX_BUTTON_CLICKS 1000

char ExtractModuleType(string& s) {
  if (s.front() != '%' && s.front() != '&') {
    return '=';
  }

  char module_type = s.front();

  reverse(s.begin(), s.end());
  s.pop_back();
  reverse(s.begin(), s.end());

  return module_type;
}

string ExtractWord(string& s) {
  reverse(s.begin(), s.end());

  while (!s.empty() && !isalpha(s.back())) {
    s.pop_back();
  }

  string t;
  while (!s.empty() && isalpha(s.back())) {
    t.push_back(s.back());
    s.pop_back();
  }

  reverse(s.begin(), s.end());

  return t;
}

string ExtractModuleName(string& s) {
  return ExtractWord(s);
}

vector<string> ParseModuleDestination(string& s) {
  vector<string> destinations;
  while (!s.empty()) {
    string destination = ExtractWord(s);
    if (!destination.empty()) {
      destinations.push_back(destination);
    }
  }
  return destinations;
}

void AddModuleType(map<string, tmodule>& modules, string& module_name, char module_type) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule(module_type, {}, {});
  } else {
    get<0>(it->second) = module_type;
  }
}

void AddSource(map<string, tmodule>& modules, string& module_name, string& source_name) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule('=', {source_name}, {});
  } else {
    get<1>(it->second).push_back(source_name);
  }
}

void AddDestination(map<string, tmodule>& modules, string& module_name, string& destination_name) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule('=', {}, {destination_name});
  } else {
    get<2>(it->second).push_back(destination_name);
  }
}

map<string, tmodule> ReadModules() {
  map<string, tmodule> modules;
  while (true) {
    string s;
    if (!getline(cin, s)) {
      break;
    }

    char module_type = ExtractModuleType(s);
    string module_name = ExtractModuleName(s);

    AddModuleType(modules, module_name, module_type);
    for (string& destination : ParseModuleDestination(s)) {
      AddSource(modules, destination, module_name);
      AddDestination(modules, module_name, destination);
    }
  }
  return modules;
}

map<string, vector<pii>> GetInitialModuleStates(map<string, tmodule>& modules, map<string, int>& flip_flop_states) {
  map<string, vector<pii>> module_states;
  for (auto [module_name, _] : modules) {
    module_states[module_name] = {{0, 0}};
  }

  for (auto [module_name, state] : flip_flop_states) {
    module_states[module_name] = {{0, state}};
  }

  return module_states;
}

pii GetLatestTimeAndSignal(map<string, vector<pii>>& module_states, string& module_name, int timer) {
  auto it = lower_bound(module_states[module_name].begin(), module_states[module_name].end(), pii{timer + 1, 0});
  it = prev(it);
  return *it;
}

int CalculateModuleSignal(map<string, tmodule>& modules, map<string, vector<pii>>& module_states, map<string, int>& flip_flop_states, string& module_name, int timer) {
  if (module_name == "broadcaster") {
    return 0;
  }

  auto [module_type, sources, _] = modules[module_name];

  if (module_type == '=') {
    return -1;
  }

  if (module_type == '%') {
    pii latest_time_and_signal = {0, 0};
    for (string& source : sources) {
      latest_time_and_signal = max(latest_time_and_signal, GetLatestTimeAndSignal(module_states, source, timer));
    }

    auto [_, latest_signal] = latest_time_and_signal;
    if (latest_signal == 1) {
      return -1;
    }

    flip_flop_states[module_name] = 1 ^ flip_flop_states[module_name];
    return flip_flop_states[module_name];
  }

  if (module_type == '&') {
    for (auto& source : sources) {
      if ((GetLatestTimeAndSignal(module_states, source, timer)).second == 0) {
        return 1;
      }
    }
    return 0;
  }

  assert(false);
}

map<string, vector<pii>> GetModuleStatesAfter1ButtonClick(map<string, tmodule>& modules, map<string, int>& flip_flop_states) {
  int timer = 0;

  map<string, vector<pii>> module_states = GetInitialModuleStates(modules, flip_flop_states);

  queue<pair<int, string>> Q;
  Q.push({timer, "broadcaster"});

  while (!Q.empty()) {
    auto [signal_time, module_name] = Q.front();
    Q.pop();

    ++timer;

    int module_signal = CalculateModuleSignal(modules, module_states, flip_flop_states, module_name, signal_time);

    if (module_signal == -1) {
      continue;
    }

    module_states[module_name].push_back({timer, module_signal});

    for (string& destination : get<2>(modules[module_name])) {
      Q.push({timer, destination});
    }
  }

  return module_states;
}

void FillFlipFlops(map<string, tmodule>& modules, set<string>& flip_flops, string module_name) {
  if (flip_flops.count(module_name)) {
    return;
  }

  auto [module_type, _, destinations] = modules[module_name];

  if (module_type == '%') {
    flip_flops.insert(module_name);
  }

  for (string& destination : destinations) {
    FillFlipFlops(modules, flip_flops, destination);
  }
}

int GetKey(set<string>& flip_flops, map<string, int>& flip_flop_states) {
  int key = 0;
  for (auto module_name : flip_flops) {
    key = key * 2 + flip_flop_states[module_name];
  }
  return key;
}

int GetCycleLength(map<string, tmodule>& modules, string module_name) {
  map<string, int> flip_flop_states;
  for (auto [module_name, module] : modules) {
    if (get<0>(module) == '%') {
      flip_flop_states[module_name] = 0;
    }
  }

  set<string> flip_flops;
  FillFlipFlops(modules, flip_flops, module_name);

  map<int, int> flip_flop_states_to_index;
  flip_flop_states_to_index[GetKey(flip_flops, flip_flop_states)] = 0;

  for (int i = 1;; ++i) {
    GetModuleStatesAfter1ButtonClick(modules, flip_flop_states);

    int key = GetKey(flip_flops, flip_flop_states);

    if (flip_flop_states_to_index.count(key)) {
      return i - flip_flop_states_to_index[key];
    }

    flip_flop_states_to_index[key] = i;
  }

  return 1;
}

int main() {
  map<string, tmodule> modules = ReadModules();

  ll ans = 1;
  for (auto& source : get<2>(modules["broadcaster"])) {
    ans = lcm(ans, GetCycleLength(modules, source));
  }

  cout << ans << "\n";

  return 0;
}