#include <iostream>
#include <conio.h> // for _getch()
#include <windows.h>

int groupingMode = 1; // 1: in folders, 2: squared, 3: no grouping
int sortingOption = 1; // 1: alphabetically, 2: by date added, 3: smart (LLM)
bool autoErrorCorrection = false; // DEV option

void clearScreen() {
    system("cls");
}

void displayMenu() {
    clearScreen();
    std::cout << "=== AuDIO Shell ===\n\n";
    std::cout << "1. Grouping mode\n";
    std::cout << "2. Sorting options\n";
    std::cout << "3. DEV options\n";
    std::cout << "4. RUN\n\n";
    std::cout << "Press 1-4 to select an option...\n";
}

void handleGroupingMode() {
    clearScreen();
    std::cout << "=== Grouping Mode ===\n\n";
    std::cout << "1. In folders\n";
    std::cout << "2. Squared\n";
    std::cout << "3. Only return list (no grouping)\n\n";
    std::cout << "Press any key to return...\n";
    _getch();
}

void handleSortingOptions() {
    clearScreen();
    std::cout << "=== Sorting Options ===\n\n";
    std::cout << "1. Alphabetically\n";
    std::cout << "2. By date added\n";
    std::cout << "3. Smart (LLM)\n\n";
    std::cout << "Press any key to return...\n";
    _getch();
}

void handleDevOptions() {
    clearScreen();
    std::cout << "=== DEV Options ===\n\n";
    std::cout << "1. Automatic error correction\n";
    std::cout << "(Run LLM multiple times and average results)\n\n";
    std::cout << "Press any key to return...\n";
    _getch();
}

int main() {
    bool running = true;
    char choice;

    while (running) {
        displayMenu();
        choice = _getch();

        switch (choice) {
            case '1':
                handleGroupingMode();
                break;
            case '2':
                handleSortingOptions();
                break;
            case '3':
                handleDevOptions();
                break;
            case '4':
                running = false;
                std::cout << "Running main program\n";
                break;
            default:
                break;
        }
    }
    
    return 0;
}