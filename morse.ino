#include "morse.h"

MorseSender* mss1 = new MorseSender(3);

void setup(void)
{
<<<<<<< HEAD
    Serial.begin(9600);
=======
    *mss1 << "Hello World!";
    delete mss1;
    *mss1 << "Hello World!";
    delete mss1;
    mss1 << "Hello World!";
>>>>>>> 45461136f9f45a283256d76ae0969c086f36ac84
}

void loop(void)
{
<<<<<<< HEAD
    char temp = Serial.read();
    if(temp != EOF && temp != '\0' && temp != '\n')
    {
        *mss1 << temp;
        delay(M__);
    }
}
=======
}
>>>>>>> 45461136f9f45a283256d76ae0969c086f36ac84
