#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

//Funcs to use in prog

std::string UserEnter();                    //User's enter
void PasswordCheck();                       //Password check
void AddData();                             //Add data

//Service funcs

std::string* StrToWord(std::string str);    //String to 'words'
int DigitEnter();                           //Protected enter

#endif // FUNCS_H_INCLUDED
