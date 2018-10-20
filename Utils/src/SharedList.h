#ifndef SHARED_LIST_H
#define SHARED_LIST_H

#include <list>
#include <mutex>
#include <algorithm>

template<class T> class SharedList {
	private:
		std::list<T> m_list;
		std::mutex m_mutex;

	public:
		std::list<T> getList() const;

		void addToList(const T& newValue);
		bool listContains(const T& valueToFind);
};

template<class T> void SharedList<T>::addToList(const T& newValue) {
	std::lock_guard<std::mutex> guard(m_mutex);
	m_list.push_back(newValue);
}

template<class T> bool SharedList<T>::listContains(const T& valueToFind) {
	std::lock_guard<std::mutex> guard(m_mutex);
	return std::find(m_list.begin(), m_list.end(), valueToFind) != m_list.end();
}

template<class T> std::list<T> SharedList<T>::getList() const { return m_list; }

#endif//SHARED_LIST_H