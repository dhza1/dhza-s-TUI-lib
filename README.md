TUI lib i made :)


example:
```cpp
#include <TUI.hpp>

int main() {
  tui.add("option 1");
  tui.add("option 2");
  // ...
  int select = tui.select();
  if (select == 0) {
    // option 1
    std::cout << "hey!" << std::endl;
  }
}
```
