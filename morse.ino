#include "morse.h"

MorseSender* mss = new MorseSender(4);
MorseRecver* msr = new MorseRecver(3);
void setup(void)
{
    Serial.begin(9600);
}
void loop(void)
{
    char temp = Serial.read();
    if(temp == EOF || temp == '\0' || temp == '\n')
    {
        Serial.print(msr->recv());
    }
    else
    {
        mss->send(temp);
        delay(M__);
    }
}
