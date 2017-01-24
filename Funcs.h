#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

//Funcs to use in prog

std::string UserEnter();                    //User's enter
void PasswordCheck();                       //Password check
void AddData();                             //Add data
void DeleteData(int pos);                   //Delete data
void ChangeStatus(int pos);                 //Change status

//Service funcs

std::string* StrToWord(std::string str);    //String to 'words'
int DigitEnter(int _min, int _max);         //Protected enter

#endif // FUNCS_H_INCLUDED
