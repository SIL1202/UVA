#include <iomanip>
#include <iostream>
using namespace std;

typedef struct {
  double x, y;
} coor;

int main() {
  coor a, b, c, d, ans;
  while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y) {
    if (a.x == c.x && a.y == c.y) { // a 和 c 是同一個點
      ans.x = b.x + d.x - a.x;
      ans.y = b.y + d.y - a.y;
    } else if (a.x == d.x && a.y == d.y) { // a 和 d 是同一個點
      ans.x = b.x + c.x - a.x;
      ans.y = b.y + c.y - a.y;
    } else if (b.x == c.x && b.y == c.y) { // b 和 c 是同一個點
      ans.x = a.x + d.x - b.x;
      ans.y = a.y + d.y - b.y;
    } else if (b.x == d.x && b.y == d.y) { // b 和 d 是同一個點
      ans.x = a.x + c.x - b.x;
      ans.y = a.y + c.y - b.y;
    }
    cout << fixed << setprecision(3) << ans.x << " " << ans.y << endl;
  }

  return 0;
}
