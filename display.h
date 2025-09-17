#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "config.h"

class Display {
public:
    static void clearScreen();
    static void mainMenu();
    static void groupingMode(Config& config);
    static void sortingOptions(Config& config);
    static void devOptions(Config& config);
    static void showFinalConfig(const Config& config);
};