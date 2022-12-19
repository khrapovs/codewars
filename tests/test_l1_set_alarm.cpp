#include <ctime>
#include <cstdlib>
#include "igloo/igloo_alt.h"
#include "010_l1_set_alarm/l1_set_alarm.h"

using namespace igloo;
using namespace std;

Describe(Set_Alarm) {
    bool set_alarm_solution(bool employed, bool vacation) {
        return employed and !vacation;
    }

    It(Test_Case) {
        bool expec = set_alarm_solution(true, true);
        Assert::That(set_alarm(true, true), Equals(expec));
        expec = set_alarm_solution(false, true);
        Assert::That(set_alarm(false, true), Equals(expec));
        expec = set_alarm_solution(false, false);
        Assert::That(set_alarm(false, false), Equals(expec));
        expec = set_alarm_solution(true, false);
        Assert::That(set_alarm(true, false), Equals(expec));
    }

    It(Random_Test_Cases) {
        srand(time(0));
        bool tests[2] = {true, false};
        for (int i = 0; i < 60; i++) {
            bool first = tests[rand() % 2];
            bool sec = tests[rand() % 2];
            bool expec = set_alarm_solution(first, sec);
            Assert::That(set_alarm(first, sec), Equals(expec));
        }
    }
};
