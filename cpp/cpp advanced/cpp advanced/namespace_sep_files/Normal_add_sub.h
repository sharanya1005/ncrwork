#pragma once
namespace Normal_ADD_SUB
{
	float operand1;
	float operand2;
	class Operation
	{
	public:
		Operation()
		{
			operand1 = 0;
			operand2 = 0;
		}
		Operation(float num_1, float num_2)
		{
			operand1 = num_1;
			operand2 = num_2;
		}
		float add(float num_1, float num_2)
		{
			float result = num_1 + num_2;
			return result;
		}
		float sub(float num_1, float num_2)
		{
			float result = num_1 - num_2;
			return result;
		}
	};
}