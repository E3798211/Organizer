#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Funcs.h"

std::string UserEnter()
{
    std::string input;          //user's input
    int status = 0;             //if input is correct

    do{
        if(status == 1)
            std::cout << "Empty message.\n";    //print message if input is incorrect

        status = 0;                             //ask for new message
        std::cout << "# ";
        getline(std::cin, input);

        if(input.empty())                       //if input is incorrect change it's status
            status = 1;

    }while(status != 0);                        //while input is incorrect

    return input;
}

void PasswordCheck()
{
    std::string password;                       //password
    std::string input;                          //user's input

    std::fstream memory("memo.txt");            //opening memory to get password
    if(!memory.is_open()){
        std::cout << "memo.txt not found.\n";
        exit(1);
    }

    getline(memory, password);
    std::cout << "Enter password.\n";

    while(1){                                   //user will not leave the loop
        input = UserEnter();                    //until password is incorrect
        if(input == password)
            break;
        std::cout << "Incorrect password.\n";
    }
}

std::string* StrToWord(std::string str)
{
    std::string* words = new std::string [255];
    int word_num = 0;                               //word's number
    bool prev_is_space = true;                      //shows if previous symbol was space

    std::string::iterator iter = str.begin();

    while(iter != str.end()){
        if(!isspace(*iter)){                        //if value is not space
            words[word_num].append(1, *iter);       //put it into the word
            prev_is_space = false;
        }else{                                      //else go to new word
            if(!prev_is_space)
                word_num++;
            prev_is_space = true;
        }
        iter++;
    }
    return words;
}

void AddData()
{
    std::ofstream data("data.txt", std::ios_base::app);         //open to write to the end
    std::string message;                                        //user's message
    int priority;                                               //message's priority
    //priority - status - text

    std::cout << "Your message:\n";
    message = UserEnter();

    std::cout << "Priority:\n";
    priority = DigitEnter(0, 10);

    data << priority << " " << "0" << " " << message << "\n";   //writing to the file
}

int DigitEnter(int _min, int _max)
{
    char input[100];                //user's input
    int value;
    bool correct = true;

    do{
        if(!correct)
            std::cout << "Incorrect enter.\n";

        std::cout << "# ";
        std::cin >> input;          //entering number
        value = std::atoi(input);   //converting to int
        correct = true;

        if(value <= _min || value >= _max)
            correct = false;
    }while(!correct);

    return value;                   //returning value
}

void DeleteData(int pos)
{
    std::fstream data("data.txt");          //opening file
    std::ofstream otmp("tmp.txt");          //creating tmp file
    std::string line;                       //string to get line from data.txt
    int counter = 0;

    while(!data.eof()){                     //put "alive" messages in tmp.txt
        std::getline(data, line);
        if(line.empty())    break;
        if(counter != pos)  otmp << line << "\n";
        counter++;
    }

    data.close();                           //closing stream to data.txt
    std::remove("data.txt");                //deleting data.txt
    std::ofstream data_new("data.txt");     //creating empty data.txt

    otmp.close();
    std::fstream itmp("tmp.txt");           //creating stream to read from tmp.txt

    while(!itmp.eof()){                     //put messages back to data.txt
        std::getline(itmp, line);
        if(line.empty())    break;
        data_new << line << "\n";
    }

    itmp.close();                           //closing streams
    data_new.close();

    std::remove("tmp.txt");                 //deleting file
}

void ChangeStatus(int pos)
{
    std::ifstream idata("data.txt");
    std::ofstream otmp("tmp.txt");          //creating tmp.txt
    std::string line_to_change;
    std::string tmp_str;
    int line_amount = 0;

    while(!idata.eof()){                    //finding the line to change
        std::getline(idata, tmp_str);       //and rewriting everything to tmp.txt
        if(tmp_str.empty()) break;

        otmp << tmp_str << "\n";

        if(line_amount == pos)              //remembering the line_to_change
            line_to_change = tmp_str;
        line_amount++;
    }

    idata.close();                                          //opening stream to data,
    std::ofstream odata("data.txt", std::ios_base::trunc);  //deleting everything
    otmp.close();
    std::ifstream itmp("tmp.txt");

    std::string::iterator iter = line_to_change.begin();    //creating iter
    while(!isspace(*iter))  iter++;
    iter++;                             //now iter looks on 'status'

    if(*iter == '0') *iter = '1';       //changing the value
    else *iter = '0';

    int counter = 0;

    while(!itmp.eof()){                 //returning everything back
        std::getline(itmp, tmp_str);
        if(tmp_str.empty()) break;

        if(counter == pos)  odata << line_to_change << "\n";
        else                odata << tmp_str << "\n";

        counter++;
    }
    odata.close();                      //close streams and deleting tmp.txt
    itmp.close();
    std::remove("tmp.txt");
}

void ChangePriority(int pos, int pri)
{
    std::ifstream idata("data.txt");
    std::ofstream otmp("tmp.txt");          //creating tmp.txt
    std::string line_to_change;
    std::string tmp_str;
    int line_amount = 0;

    while(!idata.eof()){                    //finding the line to change
        std::getline(idata, tmp_str);       //and rewriting everything to tmp.txt
        if(tmp_str.empty()) break;

        otmp << tmp_str << "\n";

        if(line_amount == pos)              //remembering the line_to_change
            line_to_change = tmp_str;
        line_amount++;
    }

    idata.close();                                          //opening stream to data,
    std::ofstream odata("data.txt", std::ios_base::trunc);  //deleting everything
    otmp.close();
    std::ifstream itmp("tmp.txt");

    std::string str = line_to_change.substr(1, std::string::npos);

    int counter = 0;

    while(!itmp.eof()){                 //returning everything back
        std::getline(itmp, tmp_str);
        if(tmp_str.empty()) break;

        if(counter == pos)  odata << pri << str << "\n";
        else                odata << tmp_str << "\n";

        counter++;
    }

    odata.close();                      //close streams and deleting tmp.txt
    itmp.close();
    std::remove("tmp.txt");
}

int MessagesAmount()
{
    std::fstream data("data.txt");
    std::string tmp;
    int lines_amount = 0;

    while(!data.eof()){
        std::getline(data, tmp);            //writing to tmp.txt
        if(tmp.empty())     break;
        lines_amount++;
    }
    return lines_amount;
}



