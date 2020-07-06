class Port
{
protected:
    int port;
    Port(int port)
    {
        this->port = port;
    }

public:
    void setPort(int port)
    {
        this->port = port;
    }
};
class DPort : public Port
{
protected:
    bool reversed;
    DPort(int port, bool reversed) : Port(port) { this->reversed = reversed; }

public:
    void setReverse(bool reversed)
    {
        this->reversed = reversed;
    }
};
class APort : public Port
{
protected:
    bool reversed;
    APort(int port, bool reversed) : Port(port) { this->reversed = reversed; }

public:
    void setReverse(bool reversed)
    {
        this->reversed = reversed;
    }
};
class DIPort : public DPort
{
public:
    DIPort(int port, bool reversed = false) : DPort(port, reversed) { pinMode(port, INPUT); }
    bool get(void)
    {
        return digitalRead(port) ^ reversed;
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, INPUT);
    }
};
class DOPort : public DPort
{
public:
    DOPort(int port, bool reversed = false) : DPort(port, reversed) { pinMode(port, OUTPUT); }
    void set(bool HoL)
    {
        digitalWrite(port, HoL ^ reversed);
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, OUTPUT);
    }
};
class AIPort : public APort
{
public:
    AIPort(int port, bool reversed = false) : APort(port, reversed) { pinMode(port, INPUT); }
    bool get(void)
    {
        int temp;
        temp = analogRead(port);
        if (reversed)
        {
            if (temp > 127)
            {
                return 255 - temp;
            }
            else
            {
                return temp + 128;
            }
        }
        else
        {
            return temp;
        }
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, INPUT);
    }
};
class AOPort : public APort
{
public:
    AOPort(int port, bool reversed = false) : APort(port, reversed) { pinMode(port, OUTPUT); }
    void set(int Lvl)
    {
        if (reversed)
        {
            if (Lvl > 127)
            {
                analogWrite(port, 255 - Lvl);
            }
            else
            {
                analogWrite(port, Lvl + 128);
            }
        }
        else
        {
            analogWrite(port, Lvl);
        }
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, OUTPUT);
    }
};
