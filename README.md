# **Morse Project**
> - Sender and Receiver  
> - **Version** 1.0

**This is a project on Arduino, aiming to perform morse code style wireless communication(Li-Fi? maybe).  
Current project have been partly completed, but bugs may be still existing, you can mail me(thewater2016@qq.com) to report if any happens, that would help a lot, thanks.XD**

**More About:**  
> - It's a disappointing news that this module **would** make program stuck(delay()), that means you probably need threads to deal with it.  
> - You actually don't need the .ino file. ~~Like you don't need an empty *WORD* file.~~  
> - The "morse.h" works on "ports.h", which means you should **not** separate them into different folders. ~~Don't make the love story filled with sadness.~~

### Current Progress:
> - Basic functions finished.  
> - Adding analog ports support.
***
### Current Classes & Functions
#### In *"ports.h"*:
- DIPort **: The class for Digital Input port.**  
  - DIPort(int port, bool reversed = false) **: Class constructor, will set target port pin mode. *port*: Set the port index of this instance. *reversed*: Set whether the input should be inverted.**
  - void setPort(int port) **: Set a port for this instance, will set target port pin mode. *port*: The port index.**
  - void setReverse(bool reversed) **: Set whether the input should be inverted. *reversed*: Yes or no.**
  - int get(void) **: Returns current value.**
