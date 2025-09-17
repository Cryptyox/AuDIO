#include "display.h"

void Display::clearScreen() {
    system("cls");
}

void Display::mainMenu() {
    clearScreen();
    std::cout << "=== AuDIO Shell ===\n\n";
    std::cout << "1. Grouping mode\n";
    std::cout << "2. Sorting options\n";
    std::cout << "3. DEV options\n";
    std::cout << "4. RUN\n\n";
    std::cout << "Press 1-4 to select an option...\n";
}

void Display::groupingMode(Config& config) {
    clearScreen();
    std::cout << "=== Grouping Mode ===\n\n";
    std::cout << "1. In folders\n";
    std::cout << "2. Squared\n";
    std::cout << "3. Only return list (no grouping)\n\n";
    std::cout << "Current setting: ";
    
    switch(config.grouping) {
        case GroupingMode::Folders: std::cout << "In folders"; break;
        case GroupingMode::Squared: std::cout << "Squared"; break;
        case GroupingMode::NoGrouping: std::cout << "No grouping"; break;
    }
    
    std::cout << "\n\nSelect option (1-3) or any other key to return...\n";
    
    char choice = _getch();
    if (choice >= '1' && choice <= '3') {
        config.grouping = static_cast<GroupingMode>(choice - '0');
        std::cout << "\nSetting updated!\n";
        Sleep(1000);
    }
}

void Display::sortingOptions(Config& config) {
    clearScreen();
    std::cout << "=== Sorting Options ===\n\n";
    std::cout << "1. Alphabetically\n";
    std::cout << "2. By date added\n";
    std::cout << "3. Smart (LLM)\n\n";
    std::cout << "Current setting: ";
    
    switch(config.sorting) {
        case SortingMode::Alphabetical: std::cout << "Alphabetical"; break;
        case SortingMode::DateAdded: std::cout << "Date Added"; break;
        case SortingMode::Smart: std::cout << "Smart (LLM)"; break;
    }
    
    std::cout << "\n\nSelect option (1-3) or any other key to return...\n";
    
    char choice = _getch();
    if (choice >= '1' && choice <= '3') {
        config.sorting = static_cast<SortingMode>(choice - '0');
        std::cout << "\nSetting updated!\n";
        Sleep(1000);
    }
}

void Display::devOptions(Config& config) {
    clearScreen();
    std::cout << "=== DEV Options ===\n\n";
    std::cout << "1. Automatic error correction\n";
    std::cout << "(Run LLM multiple times and average results)\n\n";
    std::cout << "Current setting: " << (config.autoErrorCorrection ? "ON" : "OFF") << "\n\n";
    std::cout << "Press 1 to toggle or any other key to return...\n";
    
    char choice = _getch();
    if (choice == '1') {
        config.autoErrorCorrection = !config.autoErrorCorrection;
        std::cout << "\nSetting updated!\n";
        Sleep(1000);
    }
}

void Display::showFinalConfig(const Config& config) {
    std::cout << "Running main program with configuration:\n";
    std::cout << "Grouping: " << static_cast<int>(config.grouping) << "\n";
    std::cout << "Sorting: " << static_cast<int>(config.sorting) << "\n";
    std::cout << "Auto Error Correction: " << (config.autoErrorCorrection ? "ON" : "OFF") << "\n";
}