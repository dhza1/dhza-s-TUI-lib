#ifndef TUI_HPP
#define TUI_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <ncurses.h>
void clearscreen() {
    std::system("clear"); // you might need to change this depending on your system
}
class TUI {
public:
    void add(std::string option) {
        totalamount++;
        options.insert(std::make_pair(totalamount - 1, option));
    }

    int select(std::string pre_print="") {
        while (true) {
            // start random bullshit
            initscr();
            start_color();
            init_pair(1, COLOR_BLUE, COLOR_BLACK);
            init_pair(10, COLOR_WHITE, COLOR_BLACK);
            init_pair(2, COLOR_YELLOW, COLOR_BLACK);
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
            clear();
            move(0,0);
            // god knows what printw  is but it works
            printw("Please use the ");
            attrset(COLOR_PAIR(1));
            printw("ARROW KEYS ");
            attrset(COLOR_PAIR(10));
            printw("to navegate");
            int row = 2;
            move(row,0);
            for (auto& option : options) {
                row++;
                move(row,0);
                if (option.first == selection) {
                    attrset(COLOR_PAIR(1));
                    printw("[*] >    ");
                    attrset(COLOR_PAIR(2));\
                    printw("%s", option.second.c_str());
                    attrset(COLOR_PAIR(10));
                } else {
                    attrset(COLOR_PAIR(10));
                    printw("[-] ");
                    attrset(COLOR_PAIR(3));
                    printw("%s", option.second.c_str());
                    attrset(COLOR_PAIR(10));
                }
            }
            int t = getch();
            std::cout << t << std::endl;
            if (t == 65) {
                if (selection == 0) {
                    selection = totalamount - 1;
                } else {
                    selection--;
                }
            } else if (t == 66) {
                if (selection == totalamount - 1) {
                    selection = 0;
                } else {
                    selection++;
                }
            } else if (t == 10) {
                endwin();
                return selection;
            }
        }
    }
private:
    int totalamount = 0;
    int selection = 0;
    std::map<int,std::string> options;
};
#endif
