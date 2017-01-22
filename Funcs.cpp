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

        if(input.empty() || isspace(input[0]))  //if input is incorrect change it's status
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
