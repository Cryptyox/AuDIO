#include "display.h"
#include "config.h"

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
                running = false;
                Display::showFinalConfig(config);
                Sorter::run(config);
                break;
            default:
                break;
        }
    }
    
    return 0;
}