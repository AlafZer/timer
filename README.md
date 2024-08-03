# timer
This repository provides a timer that measures and outputs time strictly in milliseconds

There are two classes: 1. timer 2. timer_exception

They are all in the alf namespace

The timer class provides the following methods:
1.start() is the method that starts the countdown
2.end() is a method that ends the countdown and outputs the difference between the end and the beginning of the countdown

You can also start the countdown in the object constructor by passing it an optional argument 'true' or 1

Also, if you started the countdown, but did not use the end() method, then the destructor will perform the work of this method when the object leaves their scope

The timer class has a private print() method, which is called in the end() method and in the destructor to output information to the console

The timer_exception class is needed in order to throw it in the end() and start() methods when you use them after the countdown has been hung and started, respectively. In the end() method, the timer_exception class is passed the string: "Ending a time that has not started", and in the start() method the string: "Starting a running timer"
The timer_exception class also provides the what() method, which returns a constant pointer to the char contained in the exception object itself.
