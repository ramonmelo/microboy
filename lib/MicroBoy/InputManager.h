#pragma once

#include "Arduino.h"

namespace microboy
{
enum Action
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ACTION,
	NONE
};

class InputManager
{
public:
	Action read();
};
} // namespace microboy
