#ifndef ORGANIZER_H_INCLUDED
#define ORGANIZER_H_INCLUDED

#include "Funcs.h"

void Organizer();
void Add(std::string* cmds, int m_amnt);
void Show(std::string* cmds, int m_amnt);
void Set(std::string* cmds, int m_amnt);
void Delete(std::string* cmds, int m_amnt);
void Change(std::string* cmds, int m_amnt);
void Close(std::string* cmds, int m_amnt);

void SetStatus(int pos, int status);
bool Answer();

#endif // ORGANIZER_H_INCLUDED
