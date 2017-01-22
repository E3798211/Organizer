#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "Funcs.h"

std::string UserEnter()
{
    std::string input;          //User's input
    int status = 0;             //If input is correct

    do{
        if(status == 1)
            std::cout << "\n\tEmpty message.";  //Print message if input is incorrect

        status = 0;                             //Ask for new message
        std::cout << "\n\n\t -> ";
        getline(std::cin, input);

        if(input.empty() || isspace(input[0]))  //if input is incorrect change it's status
            status = 1;

    }while(status != 0);

    return input;
}
