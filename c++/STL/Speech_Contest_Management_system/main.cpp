#include "speaker.h"
#include "speechManager.h"
#include <cstdlib>
#include <ctime>
#include <map>
int main (int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    SpeechManager sm;
    int choice = 0;
    while (1) {
        sm.show_Menu();
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: // begin the speech match
            sm.startSpeech();
            break;
        case 2: // check the match record
            sm.showRecord();
            break;
        case 3: // empty the match record
            sm.clearRecord();
            break;
        case 0: // exit
            sm.exitSystem();
            break;
        default:
            break;
        }
    }
    return 0;
}
