#pragma once

namespace Utils {

template<typename T>
void swap(T& a, T& b)
{
	auto temp = a;
	a = b;
	b = temp;
}

} // namespace Utils