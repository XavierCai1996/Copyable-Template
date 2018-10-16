#ifndef SIMPLE_ASSERT_H
#define SIMPLE_ASSERT_H

#include <iostream>
#include <exception>
#include <cstdlib>

//ASSERT with message
#define ASSERT_WITH_MSG(condition, message)							\
	do											\
	{											\
		if (!(condition))								\
		{										\
			std::cerr << "Assert failed."						\
				  << "condition=\"" << #condition << "\""			\
				  << ", " << message						\
				  << ". Assert @file=" << __FILE__ << ", line=" << __LINE__	\
				  << std::endl;							\
			std::terminate();							\
		}										\
	}											\
	while(false)

//ASSERT without message
#define ASSERT(condition) ASSERT_WITH_MSG(condition, "")

#endif
