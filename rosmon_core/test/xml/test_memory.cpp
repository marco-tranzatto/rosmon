// Unit tests for parsing memory sizes
// Author: Adrien Barral

#include <catch_ros/catch.hpp>

#include "../../src/launch/bytes_parser.h"

#include <tuple>

using namespace rosmon::launch;

TEST_CASE("parse memory size", "[memory]")
{
	ByteParser parser;
	uint64_t memory;
	bool ok;

	const std::vector<std::pair<std::string, uint64_t>> EXAMPLES{
		{"1  B", 1},
		{"100", 100},
		{"1 MB", 1000000ULL},
		{"1MB", 1000000ULL},
		{"1.6 GB", 1600000000ULL},
		{"1 gB", 1000000000ULL}
	};

	for(const auto& example : EXAMPLES)
	{
		std::tie(memory, ok) = parser.parseMemory(example.first);

		CAPTURE(example.first);
		CHECK(ok);
		CHECK(memory == example.second);
	}
}
