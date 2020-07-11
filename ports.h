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
class ADPort : public Port
{
protected:
    bool reversed;
    ADPort(int port, bool reversed) : Port(port) { this->reversed = reversed; }

public:
    void setReverse(bool reversed)
    {
        this->reversed = reversed;
    }
};
class DIPort : public ADPort
{
public:
    DIPort(int port, bool reversed = false) : ADPort(port, reversed) { pinMode(port, INPUT); }
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
class DOPort : public ADPort
{
public:
    DOPort(int port, bool reversed = false) : ADPort(port, reversed) { pinMode(port, OUTPUT); }
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
class AIPort : public ADPort
{
public:
    AIPort(int port, bool reversed = false) : ADPort(port, reversed) { pinMode(port, INPUT); }
    bool get(void)
    {
        int temp;
        temp = analogRead(port);
        return reversed ? 255 - temp : temp;
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, INPUT);
    }
};
class AOPort : public ADPort
{
public:
    AOPort(int port, bool reversed = false) : ADPort(port, reversed) { pinMode(port, OUTPUT); }
    void set(int Lvl)
    {
        analogWrite(port, reversed ? 255 - Lvl : Lvl);
    }
    void setPort(int port)
    {
        this->port = port;
        pinMode(port, OUTPUT);
    }
};