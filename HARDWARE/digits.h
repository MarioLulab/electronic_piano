#ifndef __DIGITS_H
#define __DIGITS_H 
#include "includes.h"

void DISPLAY_Init(void);
void digit_select(int index);
void digit_show(int digit, int index);
void display(int step, int level);
void ShowData(void* pdata);
void showFree(void);

#endif