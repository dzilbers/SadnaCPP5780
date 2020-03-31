#pragma once
template <typename T>
T myFunc(const T& x) {
	return x;
}

extern template float myFunc(const float&);
