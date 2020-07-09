#include "morse.h"

MorseRecver* msr1 = new MorseRecver(3);
void setup(void)
{
    Serial.begin(9600);
}
void loop(void)
{
    char temp = 0;
    msr1->get(temp);
    Serial.println((int)temp);
}
