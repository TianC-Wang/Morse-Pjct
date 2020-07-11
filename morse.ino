#include "morse.h"

MorseSender* mss = new MorseSender(4);
MorseRecver* msr = new MorseRecver(3);
void setup(void)
{
    Serial.begin(9600);
}
void loop(void)
{
    static unsigned int counter = 0;
    char temp = Serial.read();
    if(temp == EOF || temp == '\0' || temp == '\n')
    {
        temp = msr->recv();
        if(counter > 30 && temp == ' ')
        {
            Serial.print('\n');
            counter = 0;
        }
        Serial.print(temp);
        counter++;
    }
    else
    {
        mss->send(temp);
        delay(M__);
    }
}
