#include "Organizer.h"


using namespace std;

void Organizer()
{
    setlocale(LC_ALL, "ru");    //Russian language added

    std::string* commands;      //user's commands
    int message_amount;

    Password();

    while(1){
        message_amount = MessagesAmount();
        commands = StrToWord(UserEnter());

        if(commands[0] == "add"){
            Add(commands, message_amount);
        }else if(commands[0] == "show"){
            Show(commands, message_amount);
        }else if(commands[0] == "set"){
            Set(commands, message_amount);
        }else if(commands[0] == "delete"){
            Delete(commands, message_amount);
        }else if(commands[0] == "change"){
            Change(commands, message_amount);
        }else if(commands[0] == "help"){
            Help();
        }else if(commands[0] == "quit"){
            Quit(commands);
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
//================================================================================
        if(cmds[2].empty()){
            if(cmds[1] != "\""){
                    AddMsg(cmds);       //+++++
            }else
                cout << "Invalid message.";
//================================================================================
//================================================================================
        }else if(IsDigit(cmds[2])){                 //2-nd function
            if(cmds[3].empty()){
                if(DigitEnter(0, 9, cmds[2])){
                    AddMsgPri(cmds);    //+++++
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else
            cout << "Empty message or incorrect priority value enter.";
    }else
        cout << "Message expected after < add > .";
}

void Show(std::string* cmds, int m_amnt)
{
    if(cmds[1] == "all"){
        if(cmds[2].empty()){
            ShowAll(m_amnt);                                        //+++++
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(cmds[1] == "status"){
        if(cmds[2] == "done"){
            if(cmds[3].empty()){
                ShowStatusDone(m_amnt);                             //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "undone"){
            if(cmds[3].empty()){
                ShowStatusUndone(m_amnt);
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(cmds[1] == "priority"){
        if(cmds[2] == "high"){
            if(cmds[3].empty()){
                ShowPriorityHigh(m_amnt);                           //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "medium"){
            if(cmds[3].empty()){
                ShowPriorityMedium(m_amnt);                         //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "low"){
            if(cmds[3].empty()){
                ShowPriorityLow(m_amnt);                            //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "higher"){
            if(IsDigit(cmds[3])){
                if(DigitEnter(0, 9, cmds[3])){
                    if(cmds[4].empty()){
                        ShowPriorityHigher(cmds, m_amnt);           //+++++
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Expected priority value after < higher > .";
//================================================================================
        }else if(cmds[2] == "lower"){
            if(IsDigit(cmds[3])){
                if(DigitEnter(0, 9, cmds[3])){
                    if(cmds[4].empty()){
                        ShowPriorityLower(cmds, m_amnt);            //+++++
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Expected priority value after < lower > .";
//================================================================================
        }else if(cmds[2] == "between"){
            if(IsDigit(cmds[3])){
                if(IsDigit(cmds[4])){
                    if(DigitEnter(0, 9, cmds[3])){
                        if(DigitEnter(0, 9, cmds[4])){
                            if(cmds[5].empty()){
                                ShowPriorityBetween(cmds, m_amnt);  //+++++
                            }else
                                cout << "";
                        }else
                            cout << "Priority is out of range.";
                    }else
                        cout << "Priority is out of range.";
                }else
                    cout << "Expected second priority value.";
            }else
                cout << "Expected priority value after < higher > .";
//================================================================================
        }else if(cmds[2] == "increase"){
            if(cmds[3].empty()){
                ShowPriorityIncrease(m_amnt);                   //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "decrease"){
            if(cmds[3].empty()){
                ShowPriorityDecrease(m_amnt);                   //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
    }else
        cout << "Unknown command < " << cmds[1] << " > .";
}

void Set(std::string* cmds, int m_amnt)
{
    if(cmds[1] == "status"){                                //1-st function
        if(IsDigit(cmds[2])){                               //1.1.1 function
//================================================================================
            if(cmds[3] == "done"){
                if(DigitEnter(0, m_amnt, cmds[2])){
                    if(cmds[4].empty()){
                        SetStatusPosDone(cmds);     //+++++
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "No such message.";
//================================================================================
            }else if(cmds[3] == "undone"){                  //1.2.2 function
                if(DigitEnter(0, m_amnt, cmds[2])){
                    if(cmds[4].empty()){
                        SetStatusPosUndone(cmds);   //+++++
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
                    SetStatusAllDone(cmds, m_amnt); //+++++
                }else
                    cout << "Unknown command < " << cmds[4] << " > .";
//================================================================================
            }else if(cmds[3] == "undone"){          //1.2.2. function
                if(cmds[4].empty()){
                    SetStatusAllUndone(cmds, m_amnt);//+++++
                }else
                    cout << "Unknown command < " << cmds[4] << " > .";
//================================================================================
            }else
                cout << "Unknown command < " << cmds[3] << " > .";

        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(cmds[1] == "priority"){            //2-nd function

        if(IsDigit(cmds[2])){
            if(IsDigit(cmds[3])){
                if(cmds[4].empty()){
                    if(DigitEnter(0, m_amnt, cmds[2])){
                        if(DigitEnter(0, 9, cmds[3])){
                            SetPriority(cmds);  //+++++
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
    string tmp;

    if(cmds[1] == "all"){                           //1-st function
//================================================================================
        if(cmds[2].empty()){
            DeleteAllF();                   //+++++
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(cmds[1] == "status"){                  //2-nd function
        if(cmds[2] == "done"){                      //2.1. function
            if(cmds[3].empty()){
                DeleteStatusDone(m_amnt);       //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "undone"){
            if(cmds[3].empty()){
                DeleteStatusUndone(m_amnt);     //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(cmds[1] == "priority"){                //3-rd function
        if(cmds[2] == "high"){
            if(cmds[3].empty()){
                DeletePriorityHigh(m_amnt);     //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "medium"){
            if(cmds[3].empty()){
                DeletePriorityMedium(m_amnt);   //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "low"){
            if(cmds[3].empty()){
                DeletePriorityLow(m_amnt);      //+++++
            }else
                cout << "Unknown command < " << cmds[3] << " > .";
//================================================================================
        }else if(cmds[2] == "higher"){
            if(IsDigit(cmds[3])){
                if(DigitEnter(0, 9, cmds[3])){
                    if(cmds[4].empty()){
                        DeletePriorityHigher(cmds, m_amnt);
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Invalid enter. Expected priority value.";
//================================================================================
        }else if(cmds[2] == "lower"){
            if(IsDigit(cmds[3])){
                if(DigitEnter(0, 9, cmds[3])){
                    if(cmds[4].empty()){
                        DeletePriorityLower(cmds, m_amnt);
                    }else
                        cout << "Unknown command < " << cmds[4] << " > .";
                }else
                    cout << "Priority is out of range.";
            }else
                cout << "Invalid enter. Expected priority value.";
//================================================================================
        }else if(cmds[2] == "between"){
            if(IsDigit(cmds[3])){
                if(IsDigit(cmds[4])){
                    if(cmds[5].empty()){
                        if(DigitEnter(0, 9, cmds[3]) && DigitEnter(0, 9, cmds[4])){
                            DeletePriorityBetween(cmds, m_amnt);    //+++++
                        }else
                            cout << "Priority is out of range.";
                    }else
                        cout << "Unknown command < " << cmds[5] << " > .";
                }else
                    cout << "Invalid enter. Expected priority value.";
            }else
                cout << "Invalid enter. Expected priority value.";
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
//================================================================================
//================================================================================
    }else if(IsDigit(cmds[1])){
        if(cmds[2].empty()){
            if(DigitEnter(0, m_amnt, cmds[1])){
                DeletePos(cmds);
            }else
                cout << "No such message.";
        }else
            cout << "Unknown command < " << cmds[1] << " > .";
    }else{
        cout << "Unknown command < " << cmds[1] << " > .";
    }
}

void Change(std::string* cmds, int m_amnt)
{
    if(cmds[1] == "password"){
        if(cmds[2].empty()){
            ChangePassword();
        }else
            cout << "Unknown command < " << cmds[2] << " > .";
    }else
        cout << "Unknown command < " << cmds[1] << " > .";
}

void Help()
{
    ifstream help("help.txt");
    string tmp;

    cout << endl;
    cout << endl;

    while(!help.eof()){
        getline(help, tmp);
        cout << tmp << endl;
    }
}

void Quit(std::string* cmds)
{
    if(cmds[1].empty()){
        if(Answer()){
            exit(0);
            cout << "Bye!";
        }
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

    cout << "Are you sure? < Y > - YES, < N > - NO" << endl;
    while(1){
        words = StrToWord(UserEnter());

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

bool MsgStatus(std::string line)
{
    std::string* words = StrToWord(line);
    if(words[1] == "1"){
        delete [] words;
        return true;
    }
    delete [] words;
    return false;
}

int MsgPriority(std::string line)
{
    std::string* words = StrToWord(line);
    int value = atoi(words[0].c_str());
    delete [] words;
    return value;
}

void MsgShow(std::string line, int pos)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //console color

    string* words = StrToWord(line);

    cout << "\t" << pos << ":\t";// << words[0] << "\t";

            //correcting color
    if(atoi(words[0].c_str()) >= 7)
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 12));
    else if(atoi(words[0].c_str()) <= 2)
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 10));
    else
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 14));

    cout << words[0] << "\t";
            //correcting color
    if(words[1] == "1"){
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 10));   //writing with green
        cout << "DONE\t";
    }else{
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 12));   //writing with red
        cout << "UNDONE\t";
    }
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 7));   //returning everything back

    //breaking long string into pieces
    int str_num = 0;
    int str_pos = 0;

    string tmp = line;                                          //writing message in tmp
    tmp.erase(0, 4);

    string* strs = new string [256];

    while(str_pos <= tmp.length()){
        strs[str_num] = tmp.substr(str_pos, 30);                //copying string in strs
        str_pos += 30;                                          //changing position
        str_num++;                                              //beginning new str
    }

    str_num = 0;                                        //printing strs
    while(!strs[str_num].empty()){
        if(str_num == 0)    cout << "\t";
        else                cout << "\t\t\t\t\t";
        cout << strs[str_num] << "\n";
        str_num++;
    }

    delete [] strs;
    delete [] words;
}

void AddMsg(std::string* cmds)
{
    string msg = cmds[1].substr(1, string::npos);      //creating msg correct

    msg.erase(msg.length() - 1, string::npos);
    AddData(msg);
    cout << "New message created.";
}

void AddMsgPri(std::string* cmds)
{
    string msg = cmds[1].substr(1, string::npos);  //creating msg correct

    msg.erase(msg.length() - 1, string::npos);
    AddData(msg, cmds[2]);
    cout << "New message created.";
}

void SetStatusPosDone(std::string* cmds)
{
    SetStatus(atoi(cmds[2].c_str()), 1);
    cout << "Status changed.";
}

void SetStatusPosUndone(std::string* cmds)
{
    SetStatus(atoi(cmds[2].c_str()), 0);
    cout << "Status changed.";
}

void SetStatusAllDone(std::string* cmds, int m_amnt)
{
    for(int i = 0; i < m_amnt + 1; i++)
        SetStatus(i, 1);
    cout << "Status changed.";
}

void SetStatusAllUndone(std::string* cmds, int m_amnt)
{
    for(int i = 0; i < m_amnt + 1; i++)
        SetStatus(i, 0);
    cout << "Status changed.";
}

void SetPriority(std::string* cmds)
{
    ChangePriority(atoi(cmds[2].c_str()), atoi(cmds[3].c_str()));
    cout << "Priority changed.";
}

void DeleteAllF()
{
    if(Answer()){
        DeleteAll();
        cout << "Everything deleted.";
    }else
        cout << "Delete aborted.";
}

void DeleteStatusDone(int m_amnt)
{
    int i = 0;

    if(Answer()){
        while(i <= m_amnt){
            if(MsgStatus(GetLine(i))){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
            i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeleteStatusUndone(int m_amnt)
{
    int i = 0;

    if(Answer()){
        while(i <= m_amnt){
            if(!MsgStatus(GetLine(i))){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
            i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityHigh(int m_amnt)
{
    int i = 0;

    if(Answer()){
        while(i <= m_amnt){
            if(MsgPriority(GetLine(i)) >= 7){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
        i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityLow(int m_amnt)
{
    int i = 0;

    if(Answer()){
        while(i <= m_amnt){
            if(MsgPriority(GetLine(i)) <= 2){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
        i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityMedium(int m_amnt)
{
    int i = 0;

    if(Answer()){
        while(i <= m_amnt){
            if((MsgPriority(GetLine(i)) >= 3) && (MsgPriority(GetLine(i)) <= 6)){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
        i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityHigher(std::string* cmds, int m_amnt)
{
    int i = 0;

    if(Answer()){
        for(int k = atoi(cmds[3].c_str()); k <= 9; k++){
            while(i <= m_amnt){
                if(MsgPriority(GetLine(i)) >= k){
                    DeleteData(i);
                    m_amnt = MessagesAmount();
                    i = -1;
                }
                i++;
            }
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityLower(std::string* cmds, int m_amnt)
{
    int i = 0;

    if(Answer()){
        for(int k = atoi(cmds[3].c_str()); k >= 0; k--){
            while(i <= m_amnt){
                if(MsgPriority(GetLine(i)) <= k){
                    DeleteData(i);
                    m_amnt = MessagesAmount();
                    i = -1;
                }
                i++;
            }
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePriorityBetween(std::string* cmds, int m_amnt)
{
    int i = 0;
    int _min = atoi(cmds[3].c_str());
    int _max = atoi(cmds[4].c_str());
    int tmp;

    if(_min > _max){    //swap
        tmp = _min;
        _min = _max;
        _max = tmp;
    }

    if(Answer()){
        while(i <= m_amnt){
            if(MsgPriority(GetLine(i)) >= _min && MsgPriority(GetLine(i)) <= _max){
                DeleteData(i);
                m_amnt = MessagesAmount();
                i = 0;
                continue;
            }
            i++;
        }
        cout << "Messages deleted.";
    }else
        cout << "Delete aborted.";
}

void DeletePos(std::string* cmds)
{
    if(Answer()){
        DeleteData(atoi(cmds[1].c_str()));
        cout << "Message deleted.";
    }else
        cout << "Delete aborted.";
}

void ShowAll(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        MsgShow(GetLine(i), i);
        m_counter++;
    }
    if(m_counter == 0)  cout << "\t\tRepository is empty." << endl;
}

void ShowStatusDone(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgStatus(GetLine(i))){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowStatusUndone(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(!MsgStatus(GetLine(i))){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityHigh(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) >= 7){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityLow(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) <= 2){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityMedium(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) >= 3 && MsgPriority(GetLine(i)) <= 6){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityHigher(std::string* cmds, int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) >= atoi(cmds[3].c_str())){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityLower(std::string* cmds, int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) <= atoi(cmds[3].c_str())){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityBetween(std::string* cmds, int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;

    int _min = atoi(cmds[3].c_str());
    int _max = atoi(cmds[4].c_str());

    if(_min > _max){            //swap min and max if we need it
        int tmp = _min;
        _min = _max;
        _max = tmp;
    }

    for(int i = 0; i < m_amnt + 1; i++){
        if(MsgPriority(GetLine(i)) >= _min && MsgPriority(GetLine(i)) <= _max){
            MsgShow(GetLine(i), i);
            m_counter++;
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityDecrease(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int k = 9; k >= 0; k--){
        for(int i = 0; i < m_amnt + 1; i++){
            if(MsgPriority(GetLine(i)) == k){
                MsgShow(GetLine(i), i);
                m_counter++;
            }
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}

void ShowPriorityIncrease(int m_amnt)
{
    cout << endl;
    cout << endl;
    int m_counter = 0;
    for(int k = 0; k <= 9; k++){
        for(int i = 0; i < m_amnt + 1; i++){
            if(MsgPriority(GetLine(i)) == k){
                MsgShow(GetLine(i), i);
                m_counter++;
            }
        }
    }
    if(m_counter == 0)  cout << "\t\tNo such messages." << endl;
}



void Password()
{
    while(1){
        cout << "Enter password:\n";
        if(PasswordCheck(UserEnter())){
            cout << endl;
            cout << "Correct.\n" << endl;
            break;
        }
        cout << "Incorrect.\n\n";
    }
}

void ChangePassword()
{
    string cur_pass;
    string new_pass1;
    string new_pass2;

    while(1){
        string* tmp0;
        string* tmp1;
        string* tmp2;

        cout << "Enter current password:\n";
        cur_pass = UserEnter();
        tmp0 = StrToWord(cur_pass);
//==============================================================================
        if(tmp0[0] == "abort"){
            cout << "Password change aborted.\n";
            delete tmp0;
            delete tmp1;
            delete tmp2;
            break;
//==============================================================================
        }else if(PasswordCheck(cur_pass)){
            cout << "Enter new password:\n";
            new_pass1 = UserEnter();
            tmp1 = StrToWord(new_pass1);

            if(tmp1[0] == "abort"){              //abort
                cout << "Password change aborted.\n";
                delete [] tmp0;
                delete [] tmp1;
                delete [] tmp2;
                break;
            }

            cout << "Again:\n";
            new_pass2 = UserEnter();
            tmp2 = StrToWord(new_pass2);

            if(tmp2[0] == "abort"){              //abort
                cout << "Password change aborted.\n";
                delete [] tmp0;
                delete [] tmp1;
                delete [] tmp2;
                break;
            }

            if(new_pass1 == new_pass2){
                ofstream memo("memo.txt", std::ios_base::trunc);
                memo << new_pass2;
                cout << "Password changed.\n";
                delete [] tmp0;
                delete [] tmp1;
                delete [] tmp2;
                break;
            }
//==============================================================================
        }else{
            cout << "Incorrect.\n";
        }
        cout << "Password was not changed.\n";
        delete [] tmp0;
        delete [] tmp1;
        delete [] tmp2;
    }

}



