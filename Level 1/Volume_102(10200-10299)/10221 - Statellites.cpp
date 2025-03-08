#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double s, a;
  int r = 6440;
  while (cin >> s >> a) {
    string c;
    cin >> c;
    double h = s + r;
    double angle = a;

    if (c == "min")
      angle = a / 60.0;
    if (angle > 180.0)
      angle = 360 - angle;

    double arc = h * (M_PI * angle / 180.0);

    double chord = 2 * h * sin((angle / 2) * (M_PI / 180.0));

    cout << fixed << setprecision(6) << arc << " " << chord << endl;
  }
  return 0;
}
