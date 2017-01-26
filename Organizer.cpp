#include "Organizer.h"

using namespace std;

void Organizer()
{
    std::string* commands;      //user's commands
    int message_amount = MessagesAmount();

    while(1){
        commands = StrToWord(UserEnter());

        if(commands[0] == "add"){
            //cout << 1;
            Add(commands, message_amount);
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


void Add(std::string* cmds, int m_amnt)
{
    string msg;

    if(cmds[1][0] == '\"' && cmds[1][cmds[1].length() - 1] == '\"'){
        if(cmds[2].empty()){                        //first function

            if(cmds[1] != "\""){
                //if everything is OK
                msg = cmds[1].substr(1, string::npos);      //creating msg correct
                msg.erase(msg.length() - 1, string::npos);
                AddData(msg);
                cout << "New message created.";
                //else
            }else   cout << "Invalid message.";     //==========

        }else if(IsDigit(cmds[2])){                 //second function

            if(cmds[3].empty()){
                if(DigitEnter(0, 9, cmds[2])){
                    msg = cmds[1].substr(1, string::npos);  //creating msg correct
                    msg.erase(msg.length() - 1, string::npos);
                    AddData(msg, cmds[2]);
                    cout << "New message created.";
                }else
                    cout << "Priority lies out of range.";
            }else
                cout << "Unknown command.";
                                                    //==========
        }else
            cout << "Incorrect enter. Empty message or invalid < priority > enter.";
    }else
        cout << "Incorrect enter. Message expected after < add > .";
}

