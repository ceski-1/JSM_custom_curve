#include <cmath>
#include "Stick.h"
#include "JSMVariable.hpp"

extern vector<JSMButton> mappings;

void ScrollAxis::init(DigitalButton& negativeBtn, DigitalButton& positiveBtn, int touchpadId, int leftTrackpadId, int rightTrackpadId)
{
	_negativeButton = &negativeBtn;
	_positiveButton = &positiveBtn;
	_touchpadId = touchpadId;
	_leftTrackpadId = leftTrackpadId;
	_rightTrackpadId = rightTrackpadId;
}

void ScrollAxis::processScroll(float distance, float sens, chrono::steady_clock::time_point now)
{
	if (!_negativeButton || !_positiveButton)
		return; // not initalized!

	_leftovers += distance;
	//if (distance != 0)
	//	DEBUG_LOG << " leftover is now " << _leftovers << '\n';
	//"[" << _negativeId << "," << _positiveId << "] moved " << distance << " so that

	Pressed isPressed;
	isPressed.time_now = now;
	isPressed.turboTime = 50;
	isPressed.holdTime = 150;
	Released isReleased;
	isReleased.time_now = now;
	isReleased.turboTime = 50;
	isReleased.holdTime = 150;
	if (_pressedBtn != ButtonID::NONE)
	{
		float pressedTime = 0;
		if (_pressedBtn == _negativeButton->_id)
		{
			GetDuration dur{ now };
			pressedTime = _negativeButton->sendEvent(dur).out_duration;
			if (pressedTime < MAGIC_TAP_DURATION)
			{
				_negativeButton->sendEvent(isPressed);
				_positiveButton->sendEvent(isReleased);
				return;
			}
		}
		else // _pressedBtn == _positiveButton->_id
		{
			GetDuration dur{ now };
			pressedTime = _positiveButton->sendEvent(dur).out_duration;
			if (pressedTime < MAGIC_TAP_DURATION)
			{
				_negativeButton->sendEvent(isReleased);
				_positiveButton->sendEvent(isPressed);
				return;
			}
		}
		// pressed time > TAP_DURATION meaning release the tap
		_negativeButton->sendEvent(isReleased);
		_positiveButton->sendEvent(isReleased);
		_pressedBtn = ButtonID::NONE;
	}
	else if (fabsf(_leftovers) > sens)
	{
		if (_leftovers > 0)
		{
			_negativeButton->sendEvent(isPressed);
			_positiveButton->sendEvent(isReleased);
			_pressedBtn = _negativeButton->_id;
		}
		else
		{
			_negativeButton->sendEvent(isReleased);
			_positiveButton->sendEvent(isPressed);
			_pressedBtn = _positiveButton->_id;
		}
		_leftovers = _leftovers > 0 ? _leftovers - sens : _leftovers + sens;
	}
	// else do nothing and accumulate leftovers
}

void ScrollAxis::reset(chrono::steady_clock::time_point now)
{
	_leftovers = 0;
	Released isReleased;
	isReleased.time_now = now;
	isReleased.turboTime = 50;
	isReleased.holdTime = 150;
	_negativeButton->sendEvent(isReleased);
	_positiveButton->sendEvent(isReleased);
	_pressedBtn = ButtonID::NONE;
}

TouchStick::TouchStick(int index, shared_ptr<DigitalButton::Context> common, int handle)
	: Stick(SettingID::TOUCH_DEADZONE_INNER, SettingID::ZERO, SettingID::TOUCH_RING_MODE, SettingID::TOUCH_STICK_MODE,
		ButtonID::TRING, ButtonID::TLEFT, ButtonID::TRIGHT, ButtonID::TUP, ButtonID::TDOWN)
{
	this->_touchpadIndex = index;
	buttons.emplace(ButtonID::TUP, DigitalButton(common, mappings[int(ButtonID::TUP)]));
	buttons.emplace(ButtonID::TDOWN, DigitalButton(common, mappings[int(ButtonID::TDOWN)]));
	buttons.emplace(ButtonID::TLEFT, DigitalButton(common, mappings[int(ButtonID::TLEFT)]));
	buttons.emplace(ButtonID::TRIGHT, DigitalButton(common, mappings[int(ButtonID::TRIGHT)]));
	buttons.emplace(ButtonID::TRING, DigitalButton(common, mappings[int(ButtonID::TRING)]));
}

LeftTouchStick::LeftTouchStick(int index, shared_ptr<DigitalButton::Context> common, int handle)
	: Stick(SettingID::LTP_DEADZONE_INNER, SettingID::ZERO, SettingID::LTP_RING_MODE, SettingID::LTP_STICK_MODE,
		ButtonID::LTP_RING, ButtonID::LTP_LEFT, ButtonID::LTP_RIGHT, ButtonID::LTP_UP, ButtonID::LTP_DOWN)
{
	this->_leftTrackpadIndex = index;
	buttons.emplace(ButtonID::LTP_UP, DigitalButton(common, mappings[int(ButtonID::LTP_UP)]));
	buttons.emplace(ButtonID::LTP_DOWN, DigitalButton(common, mappings[int(ButtonID::LTP_DOWN)]));
	buttons.emplace(ButtonID::LTP_LEFT, DigitalButton(common, mappings[int(ButtonID::LTP_LEFT)]));
	buttons.emplace(ButtonID::LTP_RIGHT, DigitalButton(common, mappings[int(ButtonID::LTP_RIGHT)]));
	buttons.emplace(ButtonID::LTP_RING, DigitalButton(common, mappings[int(ButtonID::LTP_RING)]));
}

RightTouchStick::RightTouchStick(int index, shared_ptr<DigitalButton::Context> common, int handle)
	: Stick(SettingID::RTP_DEADZONE_INNER, SettingID::ZERO, SettingID::RTP_RING_MODE, SettingID::RTP_STICK_MODE,
		ButtonID::RTP_RING, ButtonID::RTP_LEFT, ButtonID::RTP_RIGHT, ButtonID::RTP_UP, ButtonID::RTP_DOWN)
{
	this->_rightTrackpadIndex = index;
	buttons.emplace(ButtonID::RTP_UP, DigitalButton(common, mappings[int(ButtonID::RTP_UP)]));
	buttons.emplace(ButtonID::RTP_DOWN, DigitalButton(common, mappings[int(ButtonID::RTP_DOWN)]));
	buttons.emplace(ButtonID::RTP_LEFT, DigitalButton(common, mappings[int(ButtonID::RTP_LEFT)]));
	buttons.emplace(ButtonID::RTP_RIGHT, DigitalButton(common, mappings[int(ButtonID::RTP_RIGHT)]));
	buttons.emplace(ButtonID::RTP_RING, DigitalButton(common, mappings[int(ButtonID::RTP_RING)]));
}
