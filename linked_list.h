#pragma once
#include "goods.h"

goods* makeNode(int x, int y, string a, string b, string c);
void print_data(goods* head);
int size(goods* head);
void find(goods*& head, int x);
void pushTop(goods*& head, int x, int y, string a, string b, string c);
void popTop(goods*& head);
void popMid(goods*& head, int position);
void edit(goods*& head, int id);