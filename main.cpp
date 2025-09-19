#include "display.h"
#include "config.h"
#include "sorter.h"

int main() {
    Config config;
    bool running = true;
    char choice;

    while (running) {
        Display::mainMenu();
        choice = _getch();

        switch (choice) {
            case '1':
                Display::groupingMode(config);
                break;
            case '2':
                Display::sortingOptions(config);
                break;
            case '3':
                Display::devOptions(config);
                break;
            case '4':
                Display::showFinalConfig(config);
                Sorter::run(config);
                running = false;
                break;
            default:
                break;
        }
    }
    
    return 0;
}