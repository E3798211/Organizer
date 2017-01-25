#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

//Funcs to use in prog

std::string UserEnter();                    //User's enter
void PasswordCheck();                       //Password check
void AddData();                             //Add data.             Check.
void DeleteData(int pos);                   //Delete data           pos is already checked
void ChangeStatus(int pos);                 //Change status         pos is already checked
void ChangePriority(int pos, int pri);      //Change Priority       pos is already checked

//Service funcs

std::string* StrToWord(std::string str);    //String to 'words'. Max amount of 'words' = 255
int DigitEnter(int _min, int _max);         //Protected enter       Check.Probably useless
int MessagesAmount();                       //Returns amount of lines in data.txt

#endif // FUNCS_H_INCLUDED
