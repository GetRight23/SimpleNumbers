#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(WrongConfigurationTest) {

public:
	TEST_METHOD(WrongConfigurationWhatsTest) {
		WrongConfigurationException wrongConfiguration;
		Assert::AreEqual(wrongConfiguration.what(), "invalid configuration");
	}
	};
}