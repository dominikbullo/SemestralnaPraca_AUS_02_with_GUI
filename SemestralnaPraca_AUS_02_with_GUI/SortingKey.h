#pragma once
#include "Area.h"

template <typename T>
class SortingKey
{
public:
	SortingKey(Obec* area);
	SortingKey(Obec* area, int kolo, T value);
	//bool operator==(const SortingKey& other) { return  value == other.value && nazov == other.nazov; };
	//bool operator!=(const SortingKey& other) { return  value != other.value && nazov != other.nazov; };
	//bool operator< (const SortingKey& x, const SortingKey& y) { return x.value < y.value };
	bool operator<(const SortingKey& other) const { return value < other.value };
	bool operator<=(const SortingKey& other) const { return value <= other.value };
	bool operator>(const SortingKey& other) const { return value > other.value };
	bool operator>=(const SortingKey& other) const { return value >= other.value };


	T getValue() { return this->value; }
private:
	const std::string nazov;
	const std::string nazovOkresu;
	const int kolo;
	const T value;
};

template<typename T>
inline SortingKey<T>::SortingKey(Obec * area)
{
}

template<typename T>
inline SortingKey<T>::SortingKey(Obec * area, int kolo, T value) :
	nazov(area->getName()),
	nazovOkresu(area->getNazovOkresu()),
	kolo(kolo),
	value(value)
{
}
