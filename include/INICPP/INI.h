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
		/**
		 * Change if global keys are permitted
		 *
		 * @param allow    should global keys be allowed?
		 * */
		void allow_global_keys(bool allow);

		void parse(std::basic_ifstream<CharT>);
	};
}
