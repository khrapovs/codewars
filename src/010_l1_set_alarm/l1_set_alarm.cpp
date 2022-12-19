#include "l1_set_alarm.h"

bool set_alarm(const bool &employed, const bool &vacation) {
    return employed and !vacation;
}
