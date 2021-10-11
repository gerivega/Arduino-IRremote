//Modified for multiple IR
#ifndef CPPLIST_H
#define CPPLIST_H

#if !defined(IR_MAXCOUNTIR)
#define IR_MAXCOUNTIR 20
#endif

#include "IRremoteInt.h"

class CppList
{
public:
  CppList();
  void Add(irparams_struct *item);
  int GetCount();
  irparams_struct* GetItem(int index);
private:
  bool Exists(void *item);
  int GetIndex(void *item);
  int _count, _maxCount;
  irparams_struct* _arr[IR_MAXCOUNTIR];
  void PrepareArray(int nextSize);
};

#endif // #ifndef CPPLIST_H
#pragma once