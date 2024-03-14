#pragma once

#include <string>
#include <fstream>
#include <uchar.h>

namespace INI
{
	template <typename T>
	struct KeyValuePair {
		std::string key;
		T value;
	};

	template <typename CharT>
	class INI
	{
	public:
		void parse(std::basic_ifstream<CharT>);
	};
}
