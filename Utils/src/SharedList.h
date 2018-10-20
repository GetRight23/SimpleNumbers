#ifndef SHARED_LIST_H
#define SHARED_LIST_H

#include <mutex>
#include <algorithm>
#include <list>

template<class T> class SharedList {
	private:
		std::list<T> m_list;
		std::mutex m_mutex;

	public:
		void addToList(const T& newValue) {
			std::lock_guard<std::mutex> guard(m_mutex);
			m_list.push_back(newValue);
		}

		bool listContains(const T& valueToFind) {
			std::lock_guard<std::mutex> guard(m_mutex);
			return std::find(m_list.begin(), m_list.end(), valueToFind) != m_list.end();
		}

		std::list<T> getList() const { return m_list; }
};
#endif//SHARED_LIST_H