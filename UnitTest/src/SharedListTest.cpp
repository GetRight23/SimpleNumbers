#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(SharedListTest) {
		private:
			SharedList<size_t> m_list;

		public:

			TEST_METHOD(SharedListAddValueTest) {
				m_list.addToList(10);
				Assert::AreEqual(m_list.getList().size(), size_t(1));
			}

			TEST_METHOD(SharedListListContains) {
				m_list.addToList(10);
				Assert::AreEqual(m_list.listContains(10), true);
			}	
	};
}