#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

//Funcs to use in prog

std::string UserEnter();                    //User's enter
bool PasswordCheck(std::string input);      //Password check

void AddData(std::string message, std::string pri); //Add data.             pri is already checked
void AddData(std::string message);          //Add data. Priority sets 0.
void DeleteData(int pos);                   //Delete data           pos is already checked
void DeleteAll();                           //Delete all data
void ChangeStatus(int pos);                 //Change status         pos is already checked
void ChangePriority(int pos, int pri);      //Change Priority       pos is already checked

//Service funcs

std::string* StrToWord(std::string str);    //String to 'words'. Max amount of 'words' = 255
bool DigitEnter(int _min, int _max, std::string input);         //Protected enter
int MessagesAmount();                       //Returns amount of lines in data.txt
bool IsDigit(std::string input);            //Returns if input is digit

#endif // FUNCS_H_INCLUDED
