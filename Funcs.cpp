#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include "Funcs.h"

std::string UserEnter()
{
    std::string input;          //User's input
    int status = 0;             //If input is correct

    do{
        if(status == 1)
            std::cout << "\nEmpty message.";    //Print message if input is incorrect

        status = 0;                             //Ask for new message
        std::cout << "\n\n -> ";
        getline(std::cin, input);

        if(input.empty())                       //if input is incorrect change it's status
            status = 1;

    }while(status != 0);                        //while input is incorrect

    return input;
}

void PasswordCheck()
{
    std::string password;                       //Password
    std::string input;                          //User's input

    std::fstream memory("memo.txt");            //Opening memory to get password
    if(!memory.is_open()){
        std::cout << "\nmemo.txt not found.";
        exit(1);
    }

    getline(memory, password);
    std::cout << "\nEnter password.";

    while(1){                                   //User will not leave the loop
        input = UserEnter();                    //until password is incorrect
        if(input == password)
            break;
        std::cout << "\nIncorrect password.";
    }
}

std::string* StrToWord(std::string str)
{
    std::string* words = new std::string [20];
    int word_num = 0;                               //Word's number
    bool prev_is_space = true;                      //Shows if previous symbol was space

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



