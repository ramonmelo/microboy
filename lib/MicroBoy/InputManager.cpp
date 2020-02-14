#include <InputManager.h>

#define RANGE 20
#define INPUT_1 0
#define INPUT_2 40
#define INPUT_3 80
#define INPUT_4 120
#define INPUT_5 170

namespace microboy
{
Action InputManager::read()
{
	int inputValue = analogRead(A0);

	if (inputValue < INPUT_1 + RANGE)
	{
		return LEFT;
	}
	else if (INPUT_2 - RANGE < inputValue && inputValue < INPUT_2 + RANGE)
	{
		return UP;
	}
	else if (INPUT_3 - RANGE < inputValue && inputValue < INPUT_3 + RANGE)
	{
		return DOWN;
	}
	else if (INPUT_4 - RANGE < inputValue && inputValue < INPUT_4 + RANGE)
	{
		return RIGHT;
	}
	else if (INPUT_5 - RANGE < inputValue && inputValue < INPUT_5 + RANGE)
	{
		return ACTION;
	}

	return NONE;
}
} // namespace microboy