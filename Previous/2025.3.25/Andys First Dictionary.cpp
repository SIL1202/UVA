#include <cctype>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  string lines;
  set<string> words;

  while (getline(cin, lines)) {
    string temp = "";
    for (int i = 0; i < lines.size(); i++) {
      char c = lines[i];
      if (isalpha(c)) {
        temp += tolower(c);
      } else {
        if (!temp.empty()) {
          words.insert(temp);
          temp = "";
        }
      }
    }
    if (!temp.empty())
      words.insert(temp);
  }
  for (auto word : words)
    cout << word << endl;
}
