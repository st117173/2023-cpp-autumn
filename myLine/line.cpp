#include "line.h"
#include "output.h"


void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void expandline(int*& line, int& size)
{
    int* newA = new int[size + 1] { 0 };
    if (line != nullptr)
    {
        for (int i = 0; i < size; ++i)
        {
            newA[i] = line[i];
        }
        delete[] line;
    }
    line = newA;
    ++size;
}

void addElement(int*& line, int& size, int element)
{
    expandline(line, size);
    line[size - 1] = element;
}

bool indexValid(int index, int size)
{
    return (index >= 0 && index < size);
}

void contractline(int*& line, int& size)
{
    if (line != nullptr)
    {
        int* newA = new int[size - 1];
        for (int i = 0; i < size - 1; ++i)
        {
            newA[i] = line[i];
        }
        delete[] line;
        line = newA;
        --size;
    }
    else
    {
        printError();
    }
}

int extractElement(int*& line, int& size, int index)
{
    int res = -1;
    if (line != nullptr)
    {
        if (indexValid(index, size))
        {
            res = line[index];
            for (int i = index; i < size - 1; ++i)
            {
                line[i] = line[i + 1];
            }
                contractline(line, size);
        }
    }
    else
    {
        printError();
        res  = -2;
    }

    return res;
}

void heapify(int* line, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && line[left] > line[largest])
    {
        largest = left;
    }

    if (right < size && line[right] > line[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(line[i], line[largest]);
        heapify(line, size, largest);
    }
}

void lineHeapSort(int*& line, int size)
{
    if (line != nullptr)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(line, size, i);
        }

        for (int i = size - 1; i >= 0; i--)
        {
            swap(line[0], line[i]);
            heapify(line, i, 0);
        }
    }
    else
    {
        printError();
    }
}



void lineSwitch(int *&line, int size)
{
    if (line != nullptr)
    {
        int maxInt = (line)[0];
        int minInt = (line)[0];
        int maxInd = 0;
        int minInd = 0;

        for (int i = 0; i < size; i++)
        {
            if (maxInt < (line)[i])
            {
                maxInt = (line)[i];
                maxInd = i;
            }
            if (minInt >= (line)[i])
            {
                minInt = (line)[i];
                minInd = i;
            }
        }
        (line)[maxInd] = minInt;
        (line)[minInd] = maxInt;
    }
    else
    {
        printError();
    }
}

void lineDeleteDuplicate(int*& line, int& size)
{
    if (line != nullptr)
    {
        int* newline = new int[size];
        int duplicate = 0;
        int newSize = 0;
        for (int i = 0; i < size; i++)
        {
            duplicate = 0;

            for (int j = 0; j < newSize; j++)
            {
                if (line[i] == newline[j])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0)
            {
                newline[newSize] = line[i];
                newSize++;
            }
        }
        delete[] line;
        size = newSize;
        line = newline;
    }
    else
    {
        printError();
    }
}

void lineReverse(int*& line, int size)
{
    if(line != nullptr)
    {
        int* newline = new int[size];

        for (int i = 0; i < size; i++)
        {
            newline[i] = line[size - 1 - i];
        }

        delete[] line;
        line = newline;
    }
    else
    {
        printError();
    }
}

void lineRandom(int*& line, int& size, int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int randomNum = rand() % (100 - (-100) + 1) - 100;
        addElement(line, size, randomNum);
    }
}
