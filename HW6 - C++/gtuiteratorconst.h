#include <iostream>

#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H
namespace EmirUzun{
	template<class T>
	class GTUIteratorConst{
	public:
		GTUIteratorConst(T* object);
		~GTUIteratorConst();

		GTUIteratorConst& operator++();
		GTUIteratorConst operator++(int);	
		GTUIteratorConst& operator--();
		GTUIteratorConst operator--(int);
		T& operator*()const;
		T* operator->()const;
		T* getPtr()const;
		GTUIteratorConst& operator=(const GTUIteratorConst& other);
		bool operator==(const GTUIteratorConst& other)const;
		bool operator!=(const GTUIteratorConst& other)const;

	private:
		T* ptr;

	};
}
#endif