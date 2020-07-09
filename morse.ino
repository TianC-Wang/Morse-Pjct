#include "morse.h"

MorseSender* mss1 = new MorseSender(3);

void setup(void)
{
    *mss1 << "Hello World!";
    delete mss1;
}

void loop(void)
{
}