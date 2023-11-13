#ifndef LINE_H
#define LINE_H

#include <cstdlib>

void swap(int& a, int& b);
void expandline(int*& line, int& size);
void addElement(int*& line, int& size, int element);
int extractElement(int*& line, int& size, int index);
void lineHeapSort(int*& line, int size);
void lineReverse(int*& line, int size);
void lineSwitch(int *&line, int size);
void lineDeleteDuplicate(int*& line, int& size);
void lineRandom(int*& line, int& size, int n);

void heapify(int* line, int size, int i);
bool indexValid(int index, int size);
void contractline(int*& line, int& size);

#endif // LINE_H

