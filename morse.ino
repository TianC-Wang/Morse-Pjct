#include "morse.h"

Morse::Analog::MorseSender* mss = new Morse::Analog::MorseSender(3);
Morse::Analog::MorseRecver* msr = new Morse::Analog::MorseRecver(5, false, 788);
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
        else
        {
            Serial.print(temp);
            counter++;
        }
    }
    else
    {
        mss->send(temp);
        delay(M__);
    }
}
