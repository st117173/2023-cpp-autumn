#ifndef BOHRVERTEX_H
#define BOHRVERTEX_H

#include <unordered_map>

struct BohrVertex
{
    std::unordered_map<char, int> nextVertices, autoMoves; // Переходы и автоматические переходы
    int patternNum;                                        // Номер шаблона
    int suffixLink;                                        // Суффиксная ссылка
    int parent;                                            // Родительская вершина
    int suffixFlink;                                       // Сжатая суффиксная ссылка
    bool isPatternEnd;                                     // Является ли конец шаблона
    char symbol;                                           // Символ

    BohrVertex(int p = -1, char c = '$');
};

#endif                                                     // BOHRVERTEX_H
