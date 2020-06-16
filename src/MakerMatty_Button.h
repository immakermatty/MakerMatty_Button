/** 
 * Author	: @makermatty (www.maker.matejsuchanek.cz)
 * Date		: 16-6-2020
 */

#ifndef _MM_BUTTON_h
#define _MM_BUTTON_h

#include <Arduino.h>
#include <Bounce2.h>

/* Use this defines before including the library for changin the wiring of the buttons */
// #define BUTTONS_INTERNAL_PULLUP_WIRED
// #define BUTTONS_PULLDOWN_WIRED

#if !defined(BUTTONS_INTERNAL_PULLUP_WIRED) && !defined(BUTTONS_PULLDOWN_WIRED)
#define BUTTONS_INTERNAL_PULLUP_WIRED
#elif defined(BUTTONS_INTERNAL_PULLUP_WIRED) && defined(BUTTONS_PULLDOWN_WIRED)
#error Buttons must be wired all the same.
#endif

#define DEFAULT_BUTTON_DEBOUNCE_MS 10

class Button
{
public:
	Button(int pinNum, int debaunceInterval = DEFAULT_BUTTON_DEBOUNCE_MS);

	void update();
	bool read();
	bool pressed();
	bool released();

private:
	const int interval;
	Bounce debouncer;
	int pin;
};

typedef Button MakerMatty_Button;


#endif