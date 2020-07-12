# **Morse Project**
> - Sender and Receiver  
> - **Version** 1.1

**This is a project on Arduino, aiming to perform morse code style wireless communication(Li-Fi? maybe).  
Current project have been partly completed, but bugs may be still existing, you can mail me(thewater2016@qq.com) to report if any happens, that would help a lot, thanks.XD**
***
**More About:**  
> - It's a disappointing news that this module **would** make program stuck(delay()), that means you probably need threads to deal with it.  
> - You actually don't need the .ino file. ~~Like you don't need an empty *WORD* file.~~  
> - The "morse.h" works on "ports.h", which means you should **not** separate them into different folders. ~~Don't make the love story filled with sadness.~~
***
### Current Progress:
> - Basic functions finished.  
> - Adding analog ports support.
***
### Current Classes & Functions
#### In *"ports.h"*:
- DIPort **: The class for Digital Input port.**  
  - DIPort(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the input of this instance should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port*: The port index.**
  - void setReverse(bool reversed) **: Set whether the input of this instance should be inverted. *reversed*: Yes or no.**
  - bool get(void) **: Returns current value of this instance.**
- DOPort **: The class for Digital Output port.**
  - DOPort(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the output of this instance should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port* The port index.**
  - void setReverse(bool reversed) **: Set whether the output of this instance should be inverted. *reversed*: Yes or no.**
  - void set(bool Hol) **: Set the current output of this instance. *Hol*: HIGH or LOW, please use true or false instead.**
- AIPort **: The class for Analog Input port.**
  - AIPort(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the input of this instance should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port*: The port index.**
  - void setReverse(bool reversed) **: Set whether the input of this instance should be inverted. *reversed*: Yes or no.**
  - int get(void) **: Returns current value of this instance.**
- AOPort **: The class for Analog Output port.**
  - AOPort(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the output of this instance should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port*: The port index.**
  - void setReverse(bool reversed) **: Set whether the output of this instance should be inverted. *reversed*: Yes or no.**
#### In *"morse.h"*
- #define **: Mostly not necessary for users.**
  - #define M_TIMEUNIT 200 **: Morse code timeunit(in msec), you can define it before including *morse.h* to cover with the length you prefer.**
  - #define M (M_TIMEUNIT/5.0f) **: The length for detecting whether the output is static.**
  - #define M_ M_TIMEUNIT **: The length for short and space between signal.**
  - #define M__ (M_TIMEUNIT\*3) **: The length for long.**
  - #define M___ (M_TIMEUNIT\*7) **: The length for blank between characters.**
  - #define M_0 **~** #define M_9 **: The RawCode of '0' ~ '9'.**
  - #define M_A **~** #define M_Z **: The RawCode of 'A' ~ 'Z'.**
  - #define M__A **~** #define M__R **: The RawCode of punctuations.**
- MorseSender **: The class for a Digital Output port, to work as a Morse code sender.**
  - MorseSender(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the out put of this instance should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port*: The port index.**
  - void setReverse(bool reversed) **: Set whether the output of this instance should be inverted. *reversed*: Yes or no.**
  - void set(bool Hol) **: Set the current output of this instance. *Hol*: HIGH or LOW, please use true or false instead.**
  - void set(int length) **: Set the current output of this instance to high, and low after some time. *length*: The length of time(in msec).**
  - void send(int rawCode) **: Send a set of signal. *rawCode*: The RawCode of the set.**
  - void send(char ch) **: Send a character or punctuation if it has a Morse code. *ch*: ASC II number of the character or punctuation.**
  - void send(const char* str) **: Send a string, the characters or punctuations which has no Morse code would be seen as space. *str*: The pointer points the first element of the string.**
  - operator<< **The same as the functions *send()*.**
