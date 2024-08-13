# timer
This repository provides a template timer class that measures and outputs time in the units that you pass to it in the template parameter and an auxiliary timer_exception class that is used to throw an exception.

They are all in the alf namespace.

The timer class provides the following methods: 1.start() is the method that starts the countdown 2.end() is the method that completes the countdown and outputs the difference between the end and the beginning of the countdown.

In order for the timer class to output the time in the units of measurement you need, then you must pass the appropriate type to the template parameter. All the types needed to pass to the template parameter are in 'std::chrono::' (these are types such as: 'nanoseconds', 'microseconds', 'milliseconds', 'seconds' and so on).

You can also start a countdown in the object constructor by passing it an optional argument 'true' or 1.

Also, if you started the countdown, but did not use the end() method, then the destructor will perform the work of this method when the object leaves its scope.

The timer class has a private print() method, which is called in the end() method and in the destructor to output information to the console.

The timer_exception class is necessary in order to call it in the end() and start() methods when you use them after the countdown has been paused and started, respectively. In the end() method, the timer_exception class is passed the string: "The end of the time that has not yet begun", and in the start() method the string: "Starting a running timer" The timer_exception class also provides the what() method, which returns a constant pointer to the character contained in the exception object itself.
