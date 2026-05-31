#pragma once

#ifndef MAGIC_ENUM_RANGE_MIN
#define MAGIC_ENUM_RANGE_MIN (-1)
#endif
#ifndef MAGIC_ENUM_RANGE_MAX
#define MAGIC_ENUM_RANGE_MAX 512
#endif

#include "magic_enum.hpp"

#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <memory>
#include <array>

// This header file is meant to be included among all core JSM source files
// And as such it should contain only constants, types and functions related to them

using namespace std; // simplify all std calls

// All enums should have an INVALID field for proper use with templated << and >> operators

enum class ButtonID
{
	INVALID = -2, // Represents an error in user input
	NONE,         //  Represents no button when explicitely stated by the user. Not to be confused with NO_HOLD_MAPPED which is no action bound.
	UP,           // = 0 as the first index
	DOWN,
	LEFT,
	RIGHT,
	L,
	ZL,
	MINUS,
	E,
	S,
	N,
	W,
	R,
	ZR,
	PLUS,
	HOME,
	LSL,
	LSR,
	RSL,
	RSR,
	L3,
	R3,
	LEAN_LEFT,
	LEAN_RIGHT,
	MIC,
	LUP,
	LDOWN,
	LLEFT,
	LRIGHT,
	LRING,
	RUP,
	RDOWN,
	RLEFT,
	RRIGHT,
	RRING,
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
	MRING,

	TOUCH,           // Touch anywhere on the touchpad
	LTP_TOUCH,       // Touch anywhere on the left trackpad
	RTP_TOUCH,       // Touch anywhere on the right trackpad

	LTOUCH,          // Left stick capacitive touch
	RTOUCH,          // Right stick capacitive touch
	LGRIP,           // Left grip sense (Steam Controller)
	RGRIP,           // Right grip sense (Steam Controller)

	LMINI,           // Left mini shoulder button
	RMINI,           // Right mini shoulder button

	MISC1,           // Additional button that varies by controller
	MISC2,           // Additional button that varies by controller
	MISC3,           // Additional button that varies by controller
	MISC4,           // Additional button that varies by controller
	MISC5,           // Additional button that varies by controller
	MISC6,           // Additional button that varies by controller

	ZLF,             // = FIRST_ANALOG_TRIGGER
	CAPTURE,         // Full press of touchpad touch + press
	LTP_CAPTURE,     // Full press of left trackpad touch + press
	RTP_CAPTURE,     // Full press of right trackpad touch + press
	//
	// Insert more analog triggers here
	//
	ZRF,             // =  LAST_ANALOG_TRIGGER

	TUP,             // Touchpad touchstick up
	TDOWN,           // Touchpad touchstick down
	TLEFT,           // Touchpad touchstick left
	TRIGHT,          // Touchpad touchstick right
	TRING,           // Touchpad touchstick ring

	LTP_UP,          // Left trackpad touchstick up
	LTP_DOWN,        // Left trackpad touchstick down
	LTP_LEFT,        // Left trackpad touchstick left
	LTP_RIGHT,       // Left trackpad touchstick right
	LTP_RING,        // Left trackpad touchstick ring

	RTP_UP,          // Right trackpad touchstick up
	RTP_DOWN,        // Right trackpad touchstick down
	RTP_LEFT,        // Right trackpad touchstick left
	RTP_RIGHT,       // Right trackpad touchstick right
	RTP_RING,        // Right trackpad touchstick ring

	SIZE, // Not a button

	// Virtual buttons configured on the touchpad. The number of buttons vary dynamically, but they each need a different ID
	T1,  // FIRST_TOUCH_BUTTON
	T2,
	T3,
	T4,
	T5,
	T6,
	T7,
	T8,
	T9,
	T10,
	T11,
	T12,
	T13,
	T14,
	T15,
	T16,
	T17,
	T18,
	T19,
	T20,
	T21,
	T22,
	T23,
	T24,
	T25, // LAST_TOUCH_BUTTON
	//
	// Add as necessary...
	//

	// Virtual buttons configured on the left trackpad grid (see LTP_MODE and LTP_GRID_SIZE)
	LTP1,  // FIRST_LTP_BUTTON
	LTP2,
	LTP3,
	LTP4,
	LTP5,
	LTP6,
	LTP7,
	LTP8,
	LTP9,
	LTP10,
	LTP11,
	LTP12,
	LTP13,
	LTP14,
	LTP15,
	LTP16,
	LTP17,
	LTP18,
	LTP19,
	LTP20,
	LTP21,
	LTP22,
	LTP23,
	LTP24,
	LTP25, // LAST_LTP_BUTTON
	//
	// Add as necessary...
	//

	// Virtual buttons configured on the right trackpad grid (see RTP_MODE and RTP_GRID_SIZE)
	RTP1,  // FIRST_RTP_BUTTON
	RTP2,
	RTP3,
	RTP4,
	RTP5,
	RTP6,
	RTP7,
	RTP8,
	RTP9,
	RTP10,
	RTP11,
	RTP12,
	RTP13,
	RTP14,
	RTP15,
	RTP16,
	RTP17,
	RTP18,
	RTP19,
	RTP20,
	RTP21,
	RTP22,
	RTP23,
	RTP24,
	RTP25, // LAST_RTP_BUTTON
	//
	// Add as necessary...
	//
};

// help strings for each button
extern const map<ButtonID, string> buttonHelpMap;

enum class SettingID
{
	INVALID = -1,
	ZERO = 0,    // Represents an error in user input
	MIN_GYRO_SENS,  // Legacy but int value not used
	MAX_GYRO_SENS,
	MIN_GYRO_THRESHOLD,
		MAX_GYRO_THRESHOLD,
		ACCEL_CURVE,
		ACCEL_NATURAL_VHALF,
		ACCEL_POWER_VREF,
		ACCEL_POWER_EXPONENT,
		ACCEL_SIGMOID_MID,
		ACCEL_SIGMOID_WIDTH,
		ACCEL_JUMP_TAU,
		STICK_POWER,
		STICK_SENS,
		REAL_WORLD_CALIBRATION,
		VIRTUAL_STICK_CALIBRATION,
		IN_GAME_SENS,
		TRIGGER_THRESHOLD,
		RESET_MAPPINGS,
		IGNORE_GYRO_DEVICES,
		NO_GYRO_BUTTON,
		LEFT_STICK_MODE,
		RIGHT_STICK_MODE,
		MOTION_STICK_MODE,
		GYRO_OFF,
		GYRO_ON,
		LEFT_STICK_AXIS,
		RIGHT_STICK_AXIS,
		MOTION_STICK_AXIS,
		TOUCH_STICK_AXIS,
		STICK_AXIS_X, // Legacy command
		STICK_AXIS_Y, // Legacy command
		GYRO_AXIS_X,
		GYRO_AXIS_Y,
		RECONNECT_CONTROLLERS,
		COUNTER_OS_MOUSE_SPEED,
		IGNORE_OS_MOUSE_SPEED,
		JOYCON_GYRO_MASK,
		JOYCON_MOTION_MASK,
		GYRO_SENS,
		FLICK_TIME,
		GYRO_SMOOTH_THRESHOLD,
		GYRO_SMOOTH_TIME,
		GYRO_SMOOTHING_DECAY,
		GYRO_CUTOFF_SPEED,
		GYRO_CUTOFF_RECOVERY,
		ONE_EURO_MIN_CUTOFF,
		ONE_EURO_SPEED_COEFF,
		GYRO_ANGLE_SNAP,
		GYRO_ANGLE_SNAP_EASE,
		DECEL_BRAKE_STRENGTH,
		DECEL_BRAKE_THRESHOLD,
		STICK_ACCELERATION_RATE,
		STICK_ACCELERATION_CAP,
	LEFT_STICK_DEADZONE_INNER,
	LEFT_STICK_DEADZONE_OUTER,
	STICK_DEADZONE_INNER,
	STICK_DEADZONE_OUTER,
	CALCULATE_REAL_WORLD_CALIBRATION,
	FINISH_GYRO_CALIBRATION,
	RESTART_GYRO_CALIBRATION,
	MOUSE_X_FROM_GYRO_AXIS,
	MOUSE_Y_FROM_GYRO_AXIS,
	ZR_MODE,
	ZL_MODE,
	AUTOLOAD,
	AUTOCONNECT,
	HELP,
	WHITELIST_SHOW,
	WHITELIST_ADD,
	WHITELIST_REMOVE,
	LEFT_RING_MODE,
	RIGHT_RING_MODE,
	MOTION_RING_MODE,
	MOUSE_RING_RADIUS,
	SCREEN_RESOLUTION_X,
	SCREEN_RESOLUTION_Y,
	ROTATE_SMOOTH_OVERRIDE,
	FLICK_SNAP_MODE,
	FLICK_SNAP_STRENGTH,
	MOTION_DEADZONE_INNER,
	MOTION_DEADZONE_OUTER,
	ANGLE_TO_AXIS_DEADZONE_INNER,
	ANGLE_TO_AXIS_DEADZONE_OUTER,
	RIGHT_STICK_DEADZONE_INNER,
	RIGHT_STICK_DEADZONE_OUTER,
	LEAN_THRESHOLD,
	FLICK_DEADZONE_ANGLE,
	FLICK_TIME_EXPONENT,
	CONTROLLER_ORIENTATION,
	GYRO_SPACE,
	ROLL_CONTRIBUTION,
	TRACKBALL_DECAY,
	TRIGGER_SKIP_DELAY,
	TURBO_PERIOD,
	HOLD_PRESS_TIME,
	TICK_TIME,
	SIM_PRESS_WINDOW, // Unchorded setting
	DBL_PRESS_WINDOW, // Unchorded setting
	GRID_SIZE,        // Unchorded setting
	TOUCHPAD_MODE,
	TOUCH_STICK_MODE,
	TOUCH_STICK_RADIUS,
	TOUCH_DEADZONE_INNER,
	TOUCH_RING_MODE,
	TOUCHPAD_SENS,
	LIGHT_BAR,
	SCROLL_SENS,
	VIRTUAL_CONTROLLER,
	RUMBLE,
	TOUCHPAD_DUAL_STAGE_MODE,
	CLEAR,
	ADAPTIVE_TRIGGER,
	LEFT_TRIGGER_EFFECT,
	RIGHT_TRIGGER_EFFECT,
	LEFT_TRIGGER_OFFSET,
	LEFT_TRIGGER_RANGE,
	RIGHT_TRIGGER_OFFSET,
	RIGHT_TRIGGER_RANGE,
	LEFT_STICK_UNDEADZONE_INNER,
	LEFT_STICK_UNDEADZONE_OUTER,
	LEFT_STICK_UNPOWER,
	RIGHT_STICK_UNDEADZONE_INNER,
	RIGHT_STICK_UNDEADZONE_OUTER,
	RIGHT_STICK_UNPOWER,
	LEFT_STICK_VIRTUAL_SCALE,
	RIGHT_STICK_VIRTUAL_SCALE,
	WIND_STICK_RANGE,
	WIND_STICK_POWER,
	UNWIND_RATE,
	GYRO_OUTPUT,
	FLICK_STICK_OUTPUT,
	HIDE_MINIMIZED,
	AUTO_CALIBRATE_GYRO,
	JSM_DIRECTORY,
	RETURN_DEADZONE_IS_ACTIVE,
	EDGE_PUSH_IS_ACTIVE,
	STICKLIKE_FACTOR,
	MOUSELIKE_FACTOR,
	RETURN_DEADZONE_ANGLE,
	RETURN_DEADZONE_ANGLE_CUTOFF,
	TELEMETRY_ENABLED,
	TELEMETRY_PORT,

	LTP_DUAL_STAGE_MODE,      // Left trackpad dual stage mode (any of the analog trigger modes), LTP_TOUCH is soft press, LTP_CAPTURE is full press
	LTP_MODE,                 // Left trackpad mode (GRID_AND_STICK or MOUSE)
	LTP_GRID_SIZE,            // Left trackpad grid size (rows and columns), uses LTP1 through LTP25
	LTP_SENS,                 // Left trackpad sensitivity in mouse mode
	LTP_STICK_MODE,           // Left trackpad touchstick mode (any of the analog stick modes)
	LTP_DEADZONE_INNER,       // Left trackpad touchstick inner deadzone
	LTP_RING_MODE,            // Left trackpad touchstick ring type (INNER or OUTER)
	LTP_STICK_RADIUS,         // Left trackpad touchstick radius size
	LTP_STICK_AXIS,           // Left trackpad touchstick axis configuration (STANDARD or INVERTED)

	RTP_DUAL_STAGE_MODE,      // Right trackpad dual stage mode (any of the analog trigger modes), RTP_TOUCH is soft press, RTP_CAPTURE is full press
	RTP_MODE,                 // Right trackpad mode (GRID_AND_STICK or MOUSE)
	RTP_GRID_SIZE,            // Right trackpad grid size (rows and columns), uses RTP1 through RTP25
	RTP_SENS,                 // Right trackpad sensitivity in mouse mode
	RTP_STICK_MODE,           // Right trackpad touchstick mode (any of the analog stick modes)
	RTP_DEADZONE_INNER,       // Right trackpad touchstick inner deadzone
	RTP_RING_MODE,            // Right trackpad touchstick ring type (INNER or OUTER)
	RTP_STICK_RADIUS,         // Right trackpad touchstick radius size
	RTP_STICK_AXIS,           // Right trackpad touchstick axis configuration (STANDARD or INVERTED)
};

// constexpr are like #define but with respect to typeness
constexpr size_t MAX_NO_OF_TOUCH = 2; // Could be obtained from JSL?
constexpr int MAPPING_SIZE = int(ButtonID::SIZE);

constexpr int FIRST_ANALOG_TRIGGER = int(ButtonID::ZLF);
constexpr int LAST_ANALOG_TRIGGER = int(ButtonID::ZRF);
constexpr int NUM_ANALOG_TRIGGERS = int(LAST_ANALOG_TRIGGER) - int(FIRST_ANALOG_TRIGGER) + 1;

// Virtual buttons configured on the touchpad grid
constexpr ButtonID FIRST_TOUCH_BUTTON = ButtonID::T1;
constexpr ButtonID LAST_TOUCH_BUTTON = ButtonID::T25;
constexpr int NUM_TOUCH_BUTTONS = int(LAST_TOUCH_BUTTON) - int(FIRST_TOUCH_BUTTON) + 1;

// Virtual buttons configured on the left trackpad grid
constexpr ButtonID FIRST_LTP_BUTTON = ButtonID::LTP1;
constexpr ButtonID LAST_LTP_BUTTON = ButtonID::LTP25;
constexpr int NUM_LTP_BUTTONS = int(LAST_LTP_BUTTON) - int(FIRST_LTP_BUTTON) + 1;

// Virtual buttons configured on the right trackpad grid
constexpr ButtonID FIRST_RTP_BUTTON = ButtonID::RTP1;
constexpr ButtonID LAST_RTP_BUTTON = ButtonID::RTP25;
constexpr int NUM_RTP_BUTTONS = int(LAST_RTP_BUTTON) - int(FIRST_RTP_BUTTON) + 1;

constexpr float MAGIC_TAP_DURATION = 40.0f;           // in milliseconds.
constexpr float MAGIC_INSTANT_DURATION = 40.0f;       // in milliseconds
constexpr float MAGIC_EXTENDED_TAP_DURATION = 500.0f; // in milliseconds
constexpr int MAGIC_TRIGGER_SMOOTHING = 5;            // in samples

enum class GyroSpace
{
	LOCAL,
	YAW_PLUS_ROLL,
	PLAYER_TURN,
	PLAYER_LEAN,
	WORLD_TURN,
	WORLD_LEAN,
	INVALID
};

enum class AccelCurve
{
	INVALID = -1,
	LINEAR = 0,
	NATURAL,
	POWER,
	QUADRATIC,
	SIGMOID,
	JUMP,
};
enum class ControllerOrientation
{
	FORWARD,
	LEFT,
	RIGHT,
	BACKWARD,
	JOYCON_SIDEWAYS,
	INVALID
};
enum class RingMode
{
	OUTER,
	INNER,
	INVALID
};
enum class StickMode
{
	NO_MOUSE,
	AIM,
	FLICK,
	FLICK_ONLY,
	ROTATE_ONLY,
	MOUSE_RING,
	MOUSE_AREA,
	OUTER_RING,
	INNER_RING,
	SCROLL_WHEEL,
	HYBRID_AIM,
	// Following requires virtual controller (keep them contiguous)
	LEFT_STICK,
	RIGHT_STICK,
	LEFT_ANGLE_TO_X,
	LEFT_ANGLE_TO_Y,
	RIGHT_ANGLE_TO_X,
	RIGHT_ANGLE_TO_Y,
	LEFT_STEER_X,
	RIGHT_STEER_X,
	LEFT_WIND_X,
	RIGHT_WIND_X,
	INVALID
};
enum class FlickSnapMode
{
	NONE,
	FOUR,
	EIGHT,
	INVALID
};
enum class AxisMode
{
	STANDARD = 1,
	INVERTED = -1,
	INVALID = 0
}; // valid values are true!
enum class TriggerMode
{
	NO_FULL,
	NO_SKIP,
	MAY_SKIP,
	MUST_SKIP,
	MAY_SKIP_R,
	MUST_SKIP_R,
	NO_SKIP_EXCLUSIVE,
	X_LT,
	X_RT,
	PS_L2 = X_LT,
	PS_R2 = X_RT,
	INVALID
};
enum class GyroAxisMask
{
	NONE = 0,
	X = 1,
	Y = 2,
	Z = 4,
	INVALID = 8
};
enum class JoyconMask
{
	IGNORE_BOTH = 0b00,
	IGNORE_LEFT = 0b01,
	IGNORE_RIGHT = 0b10,
	USE_BOTH = 0b11,
	INVALID
};
enum class GyroIgnoreMode
{
	BUTTON,
	LEFT_STICK,
	RIGHT_STICK,
	INVALID
};
enum class DstState
{
	NoPress,
	PressStart,
	QuickSoftTap,
	QuickFullPress,
	QuickFullRelease,
	SoftPress,
	DelayFullPress,
	PressStartResp,
	ExclFullPress,
	INVALID
};
enum class GyroOutput
{
	MOUSE,
	LEFT_STICK,
	RIGHT_STICK,
	PS_MOTION,
	INVALID
};

enum class BtnEvent
{
	OnPress,
	OnTap,
	OnHold,
	OnTurbo,
	OnRelease,
	OnTapRelease,
	OnHoldRelease,
	INVALID
};
enum class Switch : char
{
	OFF,
	ON,
	INVALID,
}; // Used to parse autoload assignment

enum class ControllerScheme
{
	NONE,
	XBOX,
	DS4,
	INVALID
};

enum class TouchpadMode
{
	GRID_AND_STICK, // Grid and Stick
	MOUSE,          // gestures to be added as part of this mode
	PS_TOUCHPAD,
	INVALID
};

// Workaround default string streaming operator
class PathString : public string // Should be wstring
{
public:
	PathString() = default;
	PathString(const string& path)
	  : string(path)
	{
	}
	PathString(string_view path)
	  : string(path)
	{
	}
};

union Color
{
	Color(uint32_t color = 0x00ffffff)
	  : raw(color)
	{
	}
	uint32_t raw;
	struct RGB_t
	{
		uint8_t b;
		uint8_t g;
		uint8_t r;
		uint8_t a; // unused. animation? (blink, pulse, etc)
	} rgb;
};

using AxisSignPair = pair<AxisMode, AxisMode>;

// Used for XY pair values such as sensitivity or GyroSample
// that includes a nicer accessor
struct FloatXY : public pair<float, float>
{
	FloatXY(float x = 0, float y = 0)
	  : pair(x, y)
	{
	}

	inline float x() const
	{
		return first;
	}

	inline float y() const
	{
		return second;
	}

	FloatXY &operator+=(const FloatXY& rhs)
	{
		first += rhs.first;
		second += rhs.second;
		return *this;
	}
};

// Set of gyro control settings bundled in one structure
struct GyroSettings
{
	bool always_off = false;
	ButtonID button = ButtonID::NONE; // Ignore on button none means no GYRO_OFF button (or Always On);
	GyroIgnoreMode ignore_mode = GyroIgnoreMode::BUTTON;
};

class Mapping;

// This function is defined in main.cpp. It enables two sim press variables to
// listen to each other and make sure they both hold the same values.
void updateSimPressPartner(ButtonID sim, ButtonID origin, const Mapping &newVal);
void updateDiagPressPartner(ButtonID diag, ButtonID origin, const Mapping &newVal);

// This operator enables reading any enum from string
template<class E, class = std::enable_if_t<std::is_enum<E>{}>>
istream &operator>>(istream &in, E &rhv)
{
	string s;
	in >> s;
	auto opt = magic_enum::enum_cast<E>(s);
	rhv = opt ? *opt : *magic_enum::enum_cast<E>("INVALID");
	return in;
}

// This operator enables writing any enum to string
template<class E, class = std::enable_if_t<std::is_enum<E>{}>>
ostream &operator<<(ostream &out, E rhv)
{
	return out << magic_enum::enum_name(rhv);
}

istream &operator>>(istream &in, ButtonID &rhv);
ostream &operator<<(ostream &out, const ButtonID &rhv);

istream &operator>>(istream &in, FlickSnapMode &fsm);
ostream &operator<<(ostream &out, const FlickSnapMode &fsm);

istream &operator>>(istream &in, TriggerMode &tm); // Handle L2 / R2

istream &operator>>(istream &in, GyroSettings &gyro_settings);
ostream &operator<<(ostream &out, const GyroSettings &gyro_settings);
bool operator==(const GyroSettings &lhs, const GyroSettings &rhs);
inline bool operator!=(const GyroSettings &lhs, const GyroSettings &rhs)
{
	return !(lhs == rhs);
}

ostream &operator<<(ostream &out, const FloatXY &fxy);
istream &operator>>(istream &in, FloatXY &fxy);
bool operator==(const FloatXY &lhs, const FloatXY &rhs);
inline bool operator!=(const FloatXY &lhs, const FloatXY &rhs)
{
	return !(lhs == rhs);
}

ostream& operator<<(ostream& out, const AxisSignPair& fxy);
istream& operator>>(istream& in, AxisSignPair& fxy);
bool operator==(const AxisSignPair& lhs, const AxisSignPair& rhs);
inline bool operator!=(const AxisSignPair& lhs, const AxisSignPair& rhs)
{
	return !(lhs == rhs);
}

istream &operator>>(istream &in, Color &color);
ostream &operator<<(ostream &out, const Color &color);
bool operator==(const Color &lhs, const Color &rhs);
inline bool operator!=(const Color &lhs, const Color &rhs)
{
	return !(lhs == rhs);
}

istream &operator>>(istream &in, AxisMode &am);
// AxisMode can use the templated operator for writing

istream &operator>>(istream &in, PathString &fxy);

class Log
{
public:
	enum class Level
	{
		UT,
		BASE,
		BOLD,
		INFO,
		WARN,
		ERR,
	};

protected:
	// https://stackoverflow.com/questions/11826554/standard-no-op-output-stream
	class NullBuffer : public std::streambuf
	{
	public:
		int overflow(int c) override
		{
			return c;
		}
	};
	unique_ptr<streambuf> _buf;

	static streambuf *makeBuffer(Level level);

public:
	Log(Level level)
	  : _buf(makeBuffer(level))
	  , _str(_buf.get())
	{
	}
	~Log() { }

	ostream _str;
};

// This trickery doesn't work in Linux does it? :(
#define CERR Log(Log::Level::ERR)._str
#define COUT Log(Log::Level::BASE)._str
#define COUT_INFO Log(Log::Level::INFO)._str
#define COUT_WARN Log(Log::Level::WARN)._str
#define DEBUG_LOG Log(Log::Level::UT)._str
#define COUT_BOLD Log(Log::Level::BOLD)._str

bool do_RECONNECT_CONTROLLERS(string_view arguments, std::function<void()> loadOnReconnect);
