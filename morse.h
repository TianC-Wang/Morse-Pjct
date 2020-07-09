#include "ports.h"

#pragma region TimeUnit
#ifndef M_TIMEUNIT
#define M_TIMEUNIT  200
#endif
#define M           (M_TIMEUNIT/10.0f)
#define M_          M_TIMEUNIT
#define M__         (M_TIMEUNIT*3)
#define M___        (M_TIMEUNIT*7)
#pragma endregion
#pragma region RawCode
#define MM      0b00000000 //null
#define M_A     0b00000101 //A
#define M_B     0b00011000 //B
#define M_C     0b00011010 //C
#define M_D     0b00001100 //D
#define M_E     0b00000010 //E
#define M_F     0b00010010 //F
#define M_G     0b00001110 //G
#define M_H     0b00010000 //H
#define M_I     0b00000100 //I
#define M_J     0b00010111 //J
#define M_K     0b00001101 //K
#define M_L     0b00010100 //L
#define M_M     0b00000111 //M
#define M_N     0b00000110 //N
#define M_O     0b00001111 //O
#define M_P     0b00010110 //P
#define M_Q     0b00011101 //Q
#define M_R     0b00001010 //R
#define M_S     0b00001000 //S
#define M_T     0b00000011 //T
#define M_U     0b00001001 //U
#define M_V     0b00010001 //V
#define M_W     0b00001011 //W
#define M_X     0b00011001 //X
#define M_Y     0b00011011 //Y
#define M_Z     0b00011100 //Z
#define M_0     0b00111111 //0
#define M_1     0b00101111 //1
#define M_2     0b00100111 //2
#define M_3     0b00100011 //3
#define M_4     0b00100001 //4
#define M_5     0b00100000 //5
#define M_6     0b00110000 //6
#define M_7     0b00111000 //7
#define M_8     0b00111100 //8
#define M_9     0b00111110 //9
#define M__A    0b01110011 //,
#define M__B    0b01010101 //.
#define M__C    0b01101011 //!
#define M__D    0b01001100 //?
#define M__E    0b01101010 //;
#define M__F    0b01111000 //:
#define M__G    0b01011110 //'
#define M__H    0b01010010 //"
#define M__I    0b01001101 //_
#define M__J    0b00110110 //(
#define M__K    0b01101101 //)
#define M__L    0b00110001 //=
#define M__M    0b00110010 ///
#define M__N    0b01100001 //-
#define M__O    0b00101010 //+
#define M__P    0b00101000 //&
#define M__Q    0b01011010 //@
#define M__R    0b10001001 //$
#pragma endregion

class MorseSender : public DOPort
{
public:
    MorseSender(int port, bool reversed = false) : DOPort(port, reversed) {}
    void set(bool HoL)
    {
        digitalWrite(port, HoL ^ reversed);
    }
    void set(int length)
    {
        set((bool)HIGH);
        delay(length);
        set((bool)LOW);
    }
    void send(int rawCode) //send RawCode
    {
        int translator = rawCode;
        if(translator == 0)
        {
            delay(M__);
        }
        for(int i = 0; i < 8; i++)
        {
            if(translator & 0b10000000)
            {
                translator <<= 1;
                i++;
                for(; i < 8; i++)
                {
                    if(translator & 0b10000000)
                    {
                        set(M__);
                    }
                    else
                    {
                        set(M_);
                    }
                    if(i < 7)
                    {
                        delay(M_);
                    }
                    translator <<= 1;
                }
            }
            translator <<= 1;
        }
    }
    void send(char ch) //send character
    {
        switch (ch) //switch to RawCode
        {
            case 'a':case 'A':send(M_A);break;
            case 'b':case 'B':send(M_B);break;
            case 'c':case 'C':send(M_C);break;
            case 'd':case 'D':send(M_D);break;
            case 'e':case 'E':send(M_E);break;
            case 'f':case 'F':send(M_F);break;
            case 'g':case 'G':send(M_G);break;
            case 'h':case 'H':send(M_H);break;
            case 'i':case 'I':send(M_I);break;
            case 'j':case 'J':send(M_J);break;
            case 'k':case 'K':send(M_K);break;
            case 'l':case 'L':send(M_L);break;
            case 'm':case 'M':send(M_M);break;
            case 'n':case 'N':send(M_N);break;
            case 'o':case 'O':send(M_O);break;
            case 'p':case 'P':send(M_P);break;
            case 'q':case 'Q':send(M_Q);break;
            case 'r':case 'R':send(M_R);break;
            case 's':case 'S':send(M_S);break;
            case 't':case 'T':send(M_T);break;
            case 'u':case 'U':send(M_U);break;
            case 'v':case 'V':send(M_V);break;
            case 'w':case 'W':send(M_W);break;
            case 'x':case 'X':send(M_X);break;
            case 'y':case 'Y':send(M_Y);break;
            case 'z':case 'Z':send(M_Z);break;
            case '0':send(M_0);break;
            case '1':send(M_1);break;
            case '2':send(M_2);break;
            case '3':send(M_3);break;
            case '4':send(M_4);break;
            case '5':send(M_5);break;
            case '6':send(M_6);break;
            case '7':send(M_7);break;
            case '8':send(M_8);break;
            case '9':send(M_9);break;
            case ',':send(M__A);break;
            case '.':send(M__B);break;
            case '!':send(M__C);break;
            case '?':send(M__D);break;
            case ';':send(M__E);break;
            case ':':send(M__F);break;
            case '\'':send(M__G);break;
            case '\"':send(M__H);break;
            case '_':send(M__I);break;
            case '(':send(M__J);break;
            case ')':send(M__K);break;
            case '=':send(M__L);break;
            case '/':send(M__M);break;
            case '-':send(M__N);break;
            case '+':send(M__O);break;
            case '&':send(M__P);break;
            case '@':send(M__Q);break;
            case '$':send(M__R);break;
            default:send(MM);break;
        }
    }
    void send(const char* str) //send sentence
    {
        char* ptr = (char*)str;
        int temp = 0;
        while(*ptr != '\0')
        {
            ptr++;
            temp++;
        }
        for(int i = 0; i < temp; i++)
        {
            send(str[i]);
            if(i < temp - 1)
            {
                delay(M__);
            }
        }
    }
    template<typename T>
    MorseSender operator<<(T object) //template support
    {
        send(object);
        return *this;
    }
};
class MorseRecver : public DIPort
{
private:
    bool OutOfTouch(void)
    {
        unsigned int counter = 0;
        while(counter < M)
        {
            if(get())
            {
                return false;
            }
            counter++;
            delay(1);
        }
        return true;
    }

public:
    MorseRecver(int port, bool reversed = false) : DIPort(port, reversed) {}
    bool get(void)
    {
        return digitalRead(port) ^ reversed;
    }
    void get(char* buffer)
    {
        char& temp = *buffer;
        get(temp);
    }
    void get(char& buffer)
    {
        unsigned int counter = 0;
        while(!get()) {}
        while(get())
        {
            if(!get())
            {
                
            }
            counter++;
            delay(1);
        }
    }
};