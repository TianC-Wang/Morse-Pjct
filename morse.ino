#include "morse.h"

MorseSender* mss1 = new MorseSender(3);

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    char temp = Serial.read();
    if(temp != EOF && temp != '\0' && temp != '\n')
    {
        *mss1 << temp;
        delay(M__);
    }
}