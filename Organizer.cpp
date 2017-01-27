#include "Organizer.h"

using namespace std;

void Organizer()
{
    std::string* commands;      //user's commands
    int message_amount;

    while(1){
        message_amount = MessagesAmount();
        commands = StrToWord(UserEnter());

        if(commands[0] == "add"){
            Add(commands, message_amount);
        }else if(commands[0] == "show"){
            //cout << 2;
        }else if(commands[0] == "set"){
            Set(commands, message_amount);
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
        cout << endl;
        delete [] commands;
    }
}

void Add(std::string* cmds, int m_amnt)
{
    string msg;

    if(cmds[1][0] == '\"' && cmds[1][cmds[1].length() - 1] == '\"'){    //1-st function
//================================================================================
        if(cmds[2].empty()){
            if(cmds[1] != "\""){
                msg = cmds[1].substr(1, string::npos);      //creating msg correct
                msg.erase(msg.length() - 1, string::npos);
                AddData(msg);
                cout << "New message created.";

            }else
                cout << "Invalid message.";
//================================================================================
        }else if(IsDigit(cmds[2])){                 //2-nd function
//================================================================================
            if(cmds[3].empty()){
                if(DigitEnter(0, 9, cmds[2])){
                    msg = cmds[1].substr(1, string::npos);  //creating msg correct
                    msg.erase(msg.length() - 1, string::npos);
                    AddData(msg, cmds[2]);
                    cout << "New message created.";
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else
            cout << "Incorrect enter. Empty message or invalid priority enter.";
    }else
        cout << "Incorrect enter. Message expected after < add > .";
}

void Set(std::string* cmds, int m_amnt)
{
    int pos;
    int pri;

    if(cmds[1] == "status"){                                //1-st function
        if(IsDigit(cmds[2])){                               //1.1.1 function
//================================================================================
            if(cmds[3] == "done"){
                if(DigitEnter(0, m_amnt, cmds[2])){
                    if(cmds[4].empty()){
                        pos = atoi(cmds[2].c_str());
                        SetStatus(pos, 1);
                        cout << "Status changed.";
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "No such message.";
//================================================================================
            }else if(cmds[3] == "undone"){                  //1.2.2 function
                if(DigitEnter(0, m_amnt, cmds[2])){
                    if(cmds[4].empty()){
                        pos = atoi(cmds[2].c_str());
                        SetStatus(pos, 0);
                        cout << "Status changed.";
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "No such message.";
            }else
                cout << "Unknown command < " << cmds[3] << " > .";

        }else if(cmds[2] == "all"){             //1.2. function
//================================================================================
            if(cmds[3] == "done"){                  //1.2.1. function
                if(cmds[4].empty()){
                    for(int i = 0; i < m_amnt + 1; i++)
                        SetStatus(i, 1);
                    cout << "Status changed.";
                }else
                    cout << "Unknown command < " << cmds[4] << " > .";
//================================================================================
            }else if(cmds[3] == "undone"){          //1.2.2. function
                if(cmds[4].empty()){
                    for(int i = 0; i < m_amnt + 1; i++)
                        SetStatus(i, 0);
                    cout << "Status changed.";
                }else
                    cout << "Unknown command < " << cmds[4] << " > .";
//================================================================================
            }else
                cout << "Unknown command < " << cmds[3] << " > .";

        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
    }else if(cmds[1] == "priority"){            //2-nd function

        if(IsDigit(cmds[2])){
            if(IsDigit(cmds[3])){
                if(cmds[4].empty()){
                    if(DigitEnter(0, m_amnt, cmds[2])){
                        if(DigitEnter(0, 9, cmds[3])){
                            pos = atoi(cmds[2].c_str());
                            pri = atoi(cmds[3].c_str());
                            ChangePriority(pos, pri);
                            cout << "Priority changed.";
                        }else
                            cout << "Priority is out of range.";
                    }else
                        cout << "No such message.";
                }else
                    cout << "Unknown command < " << cmds[4] << " > .";
            }else
                cout << "Incorrect enter. Priority expected after position.";
        }else
            cout << "Incorrect enter. Position expected after < priority > .";
                                                //==========
    }else
        cout << "Unknown command < " << cmds[1] << " > .";
}

void Delete(std::string* cmds, int m_amnt)
{
    if(cmds[1] == "all"){                           //1-st function
        //FIXME
    }else if(cmds[1] == "status"){                  //2-nd function
        //FIXME
    }else if(cmds[1] == "priority"){                //3-rd function
        //FIXME
    }else
        cout << "Unknown command < " << cmds[1] << " > .";
}

void SetStatus(int pos, int status)
{
    string tmp;
    string* words;
    string::iterator inter = tmp.begin();

    words = StrToWord(GetLine(pos));
    int value = atoi(words[1].c_str());

    if(value != status)     ChangeStatus(pos);

    delete [] words;
}

bool Answer()
{
    string* words;
    string tmp;

    cout << "Are you sure? < Y > - YES, < N > - NO" << endl;
    while(1){
        words = StrToWord(UserEnter());
        cout << "words[0] = " << words[0] << endl;

        if(words[0] == "Y" || words[0] == "y" || words[0] == "yes"){
            if(words[1].empty()){
                return true;
            }else
                cout << "Unknown command < " << words[1] << " > .";
        }else if(words[0] == "N" || words[0] == "n" || words[0] == "no"){
            if(words[1].empty()){
                return false;
            }else
                cout << "Unknown command < " << words[1] << " > .";
        }else if(words[0] == "abort"){
            return false;
        }else
            cout << "Unknown command < " << words[0] << " > ." << endl;

        delete [] words;
    }
}

