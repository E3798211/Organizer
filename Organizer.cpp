#include "Organizer.h"

using namespace std;

void Organizer()
{
    std::string* commands;      //user's commands

    while(1){
        commands = StrToWord(UserEnter());

              if(commands[0] == "add"){
            //cout << 1;
        }else if(commands[0] == "show"){
            //cout << 2;
        }else if(commands[0] == "set"){
            //cout << 3;
        }else if(commands[0] == "delete"){
            //cout << 4;
        }else if(commands[0] == "change"){
            //cout << 5;
        }else if(commands[0] == "close"){
            //cout << 6";
            //Ask "are you sure?", than get ans. If positive, exit(0)
            //exit(0);
        }else{
            cout << "Unknown command < " << commands[0] << " >";
        }

        cout << endl;
        delete [] commands;
    }
}
