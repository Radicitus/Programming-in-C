//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================
#include <iostream>

std::string spaces(int times) {
    std::string space_string ;
    for(int i = 0; i < times; i++) {
        space_string += " ";
    }
    return space_string;
}

void construct_row(int r, int s) {
    std::string main_top = spaces(s);
    main_top += " - ";
    std::string main_mid = spaces(s);
    main_mid += "| |";
    std::string main_bottom = spaces(s);
    main_bottom += "---";
    for (int i = 1; i < r; i++) {
        main_top += "- ";
        main_mid += " |";
        main_bottom += "--";
    }
    if (r == 1) {
        std::cout << main_top << std::endl;
    }
    std::cout << main_mid << std::endl << main_bottom;
}

void control(int rows) {
    if (rows == 1) {
        construct_row(rows, rows - 1);
    } else {
        for (int i = 1; i <= rows; ++i) {
            construct_row(i, rows - i);
            if (i != rows) {
                std::cout << std::endl;
            }
        }
    }
}

int main() {
    int rows;
    std::cin >> rows;

    control(rows);

    return 0;
}