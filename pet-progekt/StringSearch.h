#ifndef STRINGSEARCH_H
#define STRINGSEARCH_H

#include "BohrVertex.h"
#include <iostream>
#include <string>

class StringSearch {
    private:
    BohrVertex *bohr;
    std::string *patterns;
    int bohrSize;
    int patternsSize;
    int bohrCapacity;
    int patternsCapacity;

    void initializeBohr();
    void ensureBohrCapacity();
    void ensurePatternsCapacity();
    void addStringToBohr(const std::string &s);
    int getAutoMove(int vertex, char ch);
    int getSuffixLink(int vertex);
    int getSuffixFlink(int vertex);
    void check(int vertex, int i, std::ostream &outStream);
    void findAllPositions(const std::string &text, std::ostream &outStream);
    int *computePrefixFunction(const std::string &pattern);
    void findKMP(const std::string &text, const std::string &pattern, std::ostream &outStream);

    public:
    StringSearch();
    ~StringSearch();
    bool getInputFromFile(const std::string &filename, std::string &text); // Теперь публичный метод
    void findPatterns(const std::string &text,
                      const std::string &pattern,
                      int algorithmChoice,
                      std::ostream &outStream);
};

#endif // STRINGSEARCH_H
