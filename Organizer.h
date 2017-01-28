#ifndef ORGANIZER_H_INCLUDED
#define ORGANIZER_H_INCLUDED

#include "Funcs.h"

void Organizer();
void Add(std::string* cmds, int m_amnt);
void Show(std::string* cmds, int m_amnt);
void Set(std::string* cmds, int m_amnt);
void Delete(std::string* cmds, int m_amnt);
void Change(std::string* cmds, int m_amnt);
void Quit(std::string* cmds);

void SetStatus(int pos, int status);
bool Answer();
bool MsgStatus(std::string line);
int MsgPriority(std::string line);
void MsgShow(std::string line, int pos);

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
void DeletePriorityHigh(int m_amnt);
void DeletePriorityLow(int m_amnt);
void DeletePriorityMedium(int m_amnt);
void DeletePriorityHigher(std::string* cmds, int m_amnt);
void DeletePriorityLower(std::string* cmds, int m_amnt);
void DeletePriorityBetween(std::string* cmds, int m_amnt);
void ShowAll(std::string* cmds, int m_amnt);

#endif // ORGANIZER_H_INCLUDED
