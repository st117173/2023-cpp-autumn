#include "BohrVertex.h"

BohrVertex::BohrVertex(int p, char c)
    : patternNum(-1), suffixLink(-1), parent(p), suffixFlink(-1), isPatternEnd(false), symbol(c)
{
}
