#ifndef TIME_HPP
#define TIME_HPP

#include <Arduino.h>

/*
 * Object to control time
*/

class Time {
    private:
        unsigned long _time;
    public:
        enum TimeUnit {
            MILLISECOND,
            SECOND,
            MINUTE,
            HOUR,
            DAY,
            WEEK,
            MONTH,
            YEAR,
        };
        void updateTime();
        long getTime() const;
        bool waiting(unsigned long millisecond);
        bool waiting(unsigned long millisecond, TimeUnit unit);
};

#endif /* TIME_HPP */