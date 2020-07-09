#include "morse.h"

MorseSender mss1(1);

void setup(void)
{
    mss1 << "Hello World!";
}

void loop(void)
{
}