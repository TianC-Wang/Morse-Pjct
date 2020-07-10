#include "morse.h"

MorseRecver* msr1 = new MorseRecver(3, true);
void setup(void)
{
    Serial.begin(9600);
}
void loop(void)
{
    Serial.print(msr1->recv());
}
