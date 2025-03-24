#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string name;
  map<string, string> mp = {{"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"},
                            {"HALLO", "GERMAN"},  {"BONJOUR", "FRENCH"},
                            {"CIAO", "ITALIAN"},  {"ZDRAVSTVUJTE", "RUSSIAN"}};

  int i = 1;
  while (cin >> name) {
    if (name == "#")
      break;
    if (mp[name] == "") {
      cout << "Case " << i << ": UNKNOWN" << endl;
    } else {
      cout << "Case " << i << ": " << mp[name] << endl;
    }
    i++;
  }
  return 0;
}
