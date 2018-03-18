#pragma once

int setBit(int n, const unsigned idx)
{
	return n | (1 << idx);
}

int toggleBit(int n, const unsigned idx)
{
	return n ^ (1 << idx);
}

int clearBit(int n, const unsigned idx)
{
	return n & (~(1 << idx));
}

bool testBit(int n, const unsigned idx)
{
	return (n >> idx) & 1;
}

int add(int a, int b)
{
	int sum = 0;
	while(b != 0)
	{
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}

int subtract(int a, int b)
{
	int sum = 0;
	// SOLUTION 1 -> Not using add bit method

	// SOLUTION 2 -> Use add bit method
	int twosComplementOfB = 0;
	b = ~b;
	auto t = 1;
	while(t != 0)
	{
		twosComplementOfB = b ^ t;
		t = (b & t) << 1;
		b = twosComplementOfB;
	}

	while(b != 0)
	{
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}

int twosComplement(int a)
{
	return add(~a, 1);
}

int multiply(int a, int b)
{
	bool shouldNegate = false;
	if(a == 0 || b == 0)
		return 0;

	if(a < 0 && b < 0)
	{
		a = twosComplement(a);
		b = twosComplement(b);
	}
	else if(a < 0)
	{
		a = twosComplement(a);
		shouldNegate = true;
	}
	else if(b < 0)
	{
		b = twosComplement(b);
		shouldNegate = true;	
	}

	// Russian Peasant Multiplication
	int result = 0;
	while(b != 0)
	{
		if(b & 1)
			result = add(result, a);

		a <<= 1;
		b >>= 1;
	}
	return shouldNegate ? twosComplement(result) : result;
}

int division(int dv, int ds)
{
	int quotient = 0;
	bool isNegative = false;

	if(dv < 0)
	{
		dv = add(~dv, 1);
		isNegative = !isNegative;
	}

	if(ds < 0)
	{
		ds = add(~ds, 1);
		isNegative = !isNegative;
	}

	if(ds > dv || dv == 0)
		return 0;

	// SOLUTION 1 -> not optimized
	// while(dv >= ds)
	// {
	// 	dv = subtract(dv, ds);
	// 	quotient = add(quotient, 1);
	// }

	// SOLUTION 2 -> optimized
	int currentQuotientBase = 1;
	int currDs = ds;
	while(dv >= ds)
	{
		if(dv >= currDs)
		{
			dv = subtract(dv, currDs);
			quotient = add(quotient, currentQuotientBase);
			currentQuotientBase <<= 1;
			currDs <<= 1;
		}
		else
		{
			currentQuotientBase >>= 1;
			currDs >>= 1;
		}
	}

	return isNegative ? add(~quotient, 1) : quotient;
}