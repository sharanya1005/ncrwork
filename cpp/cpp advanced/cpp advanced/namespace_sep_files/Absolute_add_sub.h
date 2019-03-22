#pragma once
namespace Absolute_ADD_SUB
{

	float operand1;
	float operand2;
	class Operation_Abs
	{
	public:
		Operation_Abs()
		{
			operand1 = 0;
			operand2 = 0;
		}
		Operation_Abs(float num_1, float num_2)
		{
			operand1 = num_1;
			operand2 = num_2;
		}
	float abs_add(float num_1, float num_2)
	{
		float result = abs(num_1) + abs(num_2);
		return result;
	}
	float abs_sub(float num_1, float num_2)
	{
		float result = abs(num_1) - abs(num_2);
		return result;
	}
	};
}

