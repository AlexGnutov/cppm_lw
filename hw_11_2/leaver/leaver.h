#pragma once

#ifdef  LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif //  LEAVER_EXPORTS

#include <string>

class Leaver {
public:
	LEAVER_API std::string leave(std::string name);
};