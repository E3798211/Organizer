#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

//Funcs to use in prog

std::string UserEnter();                    //User's enter
void PasswordCheck();                       //Password check
void AddData();                             //Add data
void DeleteData(int pos);                   //Delete data
void ChangeStatus(int pos);                 //Change status
void ChangePriority(int pos, int pri);      //Change priority

//Service funcs

std::string* StrToWord(std::string str);    //String to 'words'. Max amount of 'words' = 255
int DigitEnter(int _min, int _max);         //Protected enter

#endif // FUNCS_H_INCLUDED
