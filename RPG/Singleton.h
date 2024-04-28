#pragma once

template <typename T>

class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton(const Singleton& r) = default;
	Singleton& operator=(const Singleton& r) = default;

public:
	static T* getIns()
	{
		static T ins;
		return &ins;
	}
};