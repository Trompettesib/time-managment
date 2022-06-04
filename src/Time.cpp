#include <Time.hpp>

/*
    * Update the time of this object
    * /!\ This function must be called if you want to reset the time of the object
*/
void Time::updateTime()
{
    this->_time = millis();
}


/*
    * Return the current time of this object
*/
long Time::getTime() const
{
    return this->_time;
}

/*
    * Return true if the time passed since the last update is greater than the parameter
    * /!\ This function must be called every loop
    * /!\ The parameter is in millisecond
*/
bool Time::waiting(unsigned long millisecond)
{
    if ((millis() - this->_time) > millisecond) {
        return true;
    }
    return false;
}

/*
    * Return true if the time passed since the last update is greater than the parameter
    * /!\ This function must be called every loop
    * /!\ The parameter is in the unit you choose right after
*/

bool Time::waiting(unsigned long duration, Time::TimeUnit unit)
{
    switch (unit) {
        case Time::MILLISECOND:
            return this->waiting(duration);
        case Time::SECOND:
            return this->waiting(duration * 1000);
        case Time::MINUTE:
            return this->waiting(duration * 1000 * 60);
        case Time::HOUR:
            return this->waiting(duration * 1000 * 60 * 60);
        case Time::DAY:
            return this->waiting(duration * 1000 * 60 * 60 * 24);
        case Time::WEEK:
            return this->waiting(duration * 1000 * 60 * 60 * 24 * 7);
        case Time::MONTH:
            return this->waiting(duration * 1000 * 60 * 60 * 24 * 30);
        case Time::YEAR:
            return this->waiting(duration * 1000 * 60 * 60 * 24 * 365);
        default:
            return false;
    }
}