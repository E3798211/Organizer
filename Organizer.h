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
bool MsgStatus(std::string line);
int MsgPriority(std::string line);

void AddMsg(std::string* cmds);
void AddMsgPri(std::string* cmds);
void SetStatusPosDone(std::string* cmds);
void SetStatusPosUndone(std::string* cmds);
void SetStatusAllDone(std::string* cmds, int m_amnt);
void SetStatusAllUndone(std::string* cmds, int m_amnt);
void SetPriority(std::string* cmds);
void DeleteAllF();
void DeleteStatusDone(int m_amnt);
void DeleteStatusUndone(int m_amnt);


#endif // ORGANIZER_H_INCLUDED
