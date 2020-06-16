#include "MakerMatty_Button.h"

Button::Button(int pinNum, int debaunceInterval)
    : interval(debaunceInterval)
{
    pin = pinNum;
#if defined(BUTTONS_PULLDOWN_WIRED)
    //pinMode(pin, INPUT);
    debouncer.attach(pin, INPUT);
#elif defined(BUTTONS_INTERNAL_PULLUP_WIRED)
    //pinMode(pin, INPUT_PULLUP);
    debouncer.attach(pin, INPUT_PULLUP);
#endif
    debouncer.interval(interval);
}

void Button::update()
{
    debouncer.update();
}

bool Button::read()
{
#if defined(BUTTONS_PULLDOWN_WIRED)
    return debouncer.read();
#elif defined(BUTTONS_INTERNAL_PULLUP_WIRED)
    return !debouncer.read();
#endif
}

bool Button::pressed()
{
#if defined(BUTTONS_PULLDOWN_WIRED)
    return debouncer.rose();
#elif defined(BUTTONS_INTERNAL_PULLUP_WIRED)
    return debouncer.fell();
#endif
}

bool Button::released()
{
#if defined(BUTTONS_PULLDOWN_WIRED)
    return debouncer.fell();
#elif defined(BUTTONS_INTERNAL_PULLUP_WIRED)
    return debouncer.rose();
#endif
}
