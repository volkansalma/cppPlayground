#ifndef _TEMPLATE_H
#define _TEMPLATE_H

template <class Type>
class calc
{
	
public:
	calc();
	~calc();
	Type multiply(Type a, Type b);
	Type divide(Type a, Type b);
	Type substract(Type a, Type b);
	Type add(Type a, Type b);
	
};

template <class Type>
Type calc<Type>::multiply(Type a, Type b)
{
	return a * b;
}

template<class Type>
Type calc<Type>::divide(Type a, Type b)
{
	return a / b;
}

template <class Type>
Type calc<Type>::substract(Type a, Type b)
{
	return a - b;
}

template <class Type>
Type calc<Type>::add(Type a, Type b)
{
	return a + b;
}

template <class Type>
calc<Type>::calc()
{
	;
}

template <class Type>
calc<Type>::~calc()
{
	;
}


#endif
