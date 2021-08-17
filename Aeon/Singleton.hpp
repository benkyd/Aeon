#ifndef AEON_SINGLETON_H_
#define AEON_SINGLETON_H_

namespace Aeon::Helpers {

template <class T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}

	Singleton( Singleton const& ) = delete;
	void operator=( Singleton const& ) = delete;
protected:
	Singleton() = default;
};

}

#endif
