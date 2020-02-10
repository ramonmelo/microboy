#include <InputManager.h>

#define RANGE 50
#define INPUT_1 30
#define INPUT_2 180
#define INPUT_3 340
#define INPUT_4 537
#define INPUT_5 790

namespace microboy
{
int InputManager::read()
{
	int inputValue = analogRead(A0);

	if (inputValue < INPUT_1 + RANGE)
	{
		return 1;
	}
	else if (INPUT_2 - RANGE < inputValue && inputValue < INPUT_2 + RANGE)
	{
		return 2;
	}
	else if (INPUT_3 - RANGE < inputValue && inputValue < INPUT_3 + RANGE)
	{
		return 3;
	}
	else if (INPUT_4 - RANGE < inputValue && inputValue < INPUT_4 + RANGE)
	{
		return 4;
	}
	else if (INPUT_5 - RANGE < inputValue && inputValue < INPUT_5 + RANGE)
	{
		return 5;
	}

	return 0;
}
} // namespace microboy