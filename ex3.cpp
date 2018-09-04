//2.3 Advanced Lambda Programming
//Exercise 3: Doing Mathematics in C++
//author: Leyao Zhang

#include <functional>
#include <iostream>
#include <algorithm>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

//over load add operator assignment
template <typename R, typename D>
FunctionType<R, D> operator + (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) + g(x);
	};
}
//subtract
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}
//multiply
template <typename R, typename D>
FunctionType<R, D> operator * (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}
//division
template <typename R, typename D>
FunctionType<R, D> operator / (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}
// scalar multiplication
template <typename R, typename D>
ScalarFunction operator * (double d,const FunctionType<R,D>& f)
{
	// Addition of functions
	return [=](const D& x)
	{
		return d * f(x);
	};
}
//unary additive inverse 
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f)
{
	// Addition of functions
	return [=](const D& x)
	{
		return -f(x);
	};
}
//Nesting
template <typename R, typename D>
FunctionType<R, D> operator << (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Addition of functions
	return [=](const D& x)
	{
		return f(g(x))  ;
	};
}
//exp
template <typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::exp(f(x));
	};
}
//cos
template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}
//sin
template <typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::sin(f(x));
	};
}
//tan
template <typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::tan(f(x));
	};
}
//log
template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}
//abs
template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}
//sqrt
template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::sqrt(f(x));
	};
}
//max
template <typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::max(f(x),g(x));
	};
}
//min
template <typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// The exponential function
	return [=](const D& x)
	{
		return std::min(f(x), g(x));
	};
}


int main()
{//ex3.a)........................................................................
	// Scalar functions: double to double
	ScalarFunction f = [](double x) {return x*x; };
	ScalarFunction g = [=](double x) { return x; };

	std::cout << g(2) << ", " << g(8) << "*";
	// Set I: Arithmetic functions

	double scale = 2.0;
	auto fA = 2.0 * (f + g);
	auto fM = f - g;
	auto fD = f / g;
	auto fMul = f * g;
	auto fC = g << g << 4.0 * g;// Compose
	auto fMinus = -(f + g);

	double x = 5.0;

	std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", "
		<< fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x);


	//ex3.b).........................................................................................
	auto ftmp = log(g);
	auto ftmp2 = cos(f);
	auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2;
	std::cout << f2(x) << std::endl;


	//ex3.c).........................................................................................
	auto h1 = min(f, g);
	auto h2 = max(f, g);
	std::cout << "min(f,g): " << h1(2.0) << '\n';
	std::cout << "max(f,g): " << h2(2.0) << '\n';
	auto h3 = min(h1, max(2 * f, 3 * g));
	auto h4 = max(h2, max(-2 * f, 3 * g));
	std::cout << "h3(2): " << h3(2.0) << '\n';
	std::cout << "h4(2): " << h4(2.0) << '\n';
	return 0;
}