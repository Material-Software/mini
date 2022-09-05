#define DEBUG 1

#if DEBUG
	#include <iostream>
	#define logl(x) std::cout << x << std::endl
#else
	#define logl(x)
#endif
