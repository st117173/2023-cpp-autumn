#include "StringSearch.h"
#include <fstream>
#include <sstream>

StringSearch::StringSearch()
    : bohr(nullptr), patterns(nullptr), bohrSize(0), patternsSize(0), bohrCapacity(0), patternsCapacity(0)
{
}

StringSearch::~StringSearch()
{
    delete[] bohr;
    delete[] patterns;
}

void StringSearch::initializeBohr()
{
    delete[] bohr;
    delete[] patterns;
    bohrCapacity = 1000;          // Начальная вместимость массива вершин
    patternsCapacity = 100;       // Начальная вместимость массива шаблонов
    bohr = new BohrVertex[bohrCapacity];
    patterns = new std::string[patternsCapacity];
    bohrSize = 1;
    bohr[0] = BohrVertex(0, '$'); // Добавляем корневую вершину
    patternsSize = 0;
}

void StringSearch::ensureBohrCapacity()
{
    if (bohrSize >= bohrCapacity)
    {
        bohrCapacity *= 2;
        BohrVertex *newBohr = new BohrVertex[bohrCapacity];
        for (int i = 0; i < bohrSize; ++i)
        {
            newBohr[i] = bohr[i];
        }
        delete[] bohr;
        bohr = newBohr;
    }
}

void StringSearch::ensurePatternsCapacity()
{
    if (patternsSize >= patternsCapacity)
    {
        patternsCapacity *= 2;
        std::string *newPatterns = new std::string[patternsCapacity];
        for (int i = 0; i < patternsSize; ++i)
        {
            newPatterns[i] = patterns[i];
        }
        delete[] patterns;
        patterns = newPatterns;
    }
}

void StringSearch::addStringToBohr(const std::string &s)
{
    int num = 0; // Начинаем с корневой вершины
    for (char ch : s)
    {
        if (bohr[num].nextVertices.find(ch) == bohr[num].nextVertices.end())
        {
            ensureBohrCapacity();
            bohr[bohrSize] = BohrVertex(num, ch);  // Добавляем новую вершину
            bohr[num].nextVertices[ch] = bohrSize; // Обновляем переход
            ++bohrSize;
        }
        num = bohr[num].nextVertices[ch];          // Переходим к следующей вершине
    }
    bohr[num].isPatternEnd = true;                 // Отмечаем конец шаблона
    ensurePatternsCapacity();
    patterns[patternsSize] = s;                    // Добавляем шаблон в массив шаблонов
    bohr[num].patternNum = patternsSize;           // Обновляем номер шаблона
    ++patternsSize;
}

int StringSearch::getAutoMove(int vertex, char ch)
{
    if (bohr[vertex].autoMoves.find(ch) == bohr[vertex].autoMoves.end())
    {
        if (bohr[vertex].nextVertices.find(ch) != bohr[vertex].nextVertices.end())
        {
            bohr[vertex].autoMoves[ch] = bohr[vertex].nextVertices[ch]; // Автоматический переход
        }
        else
        {
            bohr[vertex].autoMoves[ch] =
                (vertex == 0 ? 0 : getAutoMove(getSuffixLink(vertex), ch)); // Суффиксная ссылка
        }
    }
    return bohr[vertex].autoMoves[ch];
}

int StringSearch::getSuffixLink(int vertex)
{
    if (bohr[vertex].suffixLink == -1)
    {
        if (vertex == 0 || bohr[vertex].parent == 0)
        {
            bohr[vertex].suffixLink = 0; // Суффиксная ссылка для корня или его детей
        }
        else
        {
            bohr[vertex].suffixLink = getAutoMove(getSuffixLink(bohr[vertex].parent), bohr[vertex].symbol);
        }
    }
    return bohr[vertex].suffixLink;
}

int StringSearch::getSuffixFlink(int vertex)
{
    if (bohr[vertex].suffixFlink == -1)
    {
        int suffLink = getSuffixLink(vertex);
        if (suffLink == 0)
        {
            bohr[vertex].suffixFlink = 0; // Сжатая суффиксная ссылка для корня
        }
        else
        {
            bohr[vertex].suffixFlink = bohr[suffLink].isPatternEnd ? suffLink : getSuffixFlink(suffLink);
        }
    }
    return bohr[vertex].suffixFlink;
}

void StringSearch::check(int vertex, int i, std::ostream &outStream)
{
    for (int v = vertex; v != 0; v = getSuffixFlink(v))
    {
        if (bohr[v].isPatternEnd)
        {
            outStream << "Позиция: " << i - patterns[bohr[v].patternNum].length() + 1
                      << " Шаблон: " << patterns[bohr[v].patternNum] << std::endl;
        }
    }
}

void StringSearch::findAllPositions(const std::string &text, std::ostream &outStream)
{
    int vertex = 0;
    for (int i = 0; i < text.length(); i++)
    {
        vertex = getAutoMove(vertex, text[i]);
        outStream << "Промежуточный результат: " << i << " символ: \"" << text[i] << "\"" << std::endl;
        check(vertex, i + 1, outStream);
    }
}

int *StringSearch::computePrefixFunction(const std::string &pattern)
{
    int m = pattern.length();
    int *pi = new int[m]();
    int k = 0;
    for (int i = 1; i < m; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i])
        {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}

void StringSearch::findKMP(const std::string &text, const std::string &pattern, std::ostream &outStream)
{
    int n = text.length();
    int m = pattern.length();
    int *pi = computePrefixFunction(pattern);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            outStream << "Промежуточный результат: позиция: " << i << " символ: \"" << text[i]
                      << "\" не совпадает, откат к: " << q - 1 << std::endl;
            q = pi[q - 1];
        }
        if (pattern[q] == text[i])
        {
            q++;
            outStream << "Промежуточный результат: позиция: " << i << " символ: \"" << text[i]
                      << "\" совпадает, длина текущего совпадения: " << q << std::endl;
        }
        if (q == m)
        {
            outStream << "Шаблон найден на позиции " << i - m + 1 << std::endl;
            q = pi[q - 1];
        }
    }
    delete[] pi;
}

bool StringSearch::getInputFromFile(const std::string &filename, std::string &text)
{
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return false;
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf(); // Чтение всего файла в буфер
    text = buffer.str();
    inFile.close();
    return true;
}

void StringSearch::findPatterns(const std::string &text,
                                const std::string &pattern,
                                int algorithmChoice,
                                std::ostream &outStream)
{
    if (algorithmChoice == 1)
    {
        findKMP(text, pattern, outStream);
    }
    else if (algorithmChoice == 2)
    {
        initializeBohr();
        addStringToBohr(pattern);
        findAllPositions(text, outStream);
    }
}
