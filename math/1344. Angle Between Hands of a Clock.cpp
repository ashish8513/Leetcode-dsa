// Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

// Answers within 10-5 of the actual value will be accepted as correct.
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minutes) {

        double minuteAngle = minutes * 6.0;

        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360.0 - angle);
    }
};