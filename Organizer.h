#ifndef ORGANIZER_H_INCLUDED
#define ORGANIZER_H_INCLUDED

#include "Funcs.h"

void Organizer();
void Add(std::string* cmds, int m_amnt);
void Show(std::string* cmds);
void Set(std::string* cmds);
void Delete(std::string* cmds);
void Change(std::string* cmds);
void Close(std::string* cmds);

#endif // ORGANIZER_H_INCLUDED
