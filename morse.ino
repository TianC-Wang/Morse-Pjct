#include "morse.h"

MorseSender* mss1 = new MorseSender(3);

void setup(void)
{
<<<<<<< HEAD
    *mss1 << "Hello World!";
    delete mss1;
=======
    mss1 << "Hello World!";
>>>>>>> 32c9b5201b240cead70b3f036fe41a5f2bc6a537
}

void loop(void)
{
}