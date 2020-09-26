#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

// Pedro Escoboza
// A01251531
// 07/09/2020
// TC1031.501

#include <algorithm>
#include <iterator>

namespace alg {

	// Sorts random access iterator range by quick sort.
	// Time complexity: O(n*log(n))
	template<typename It>
	void quick_sort(It begin, It end);
	
	// Wrapper for containers defining begin and end
	template <typename Container>
	void quick_sort(const Container& container);
	
	// Searches for key in sorted iterator range. Returns iterator of element or end.
	// Time complexity: O(log(n))
	template <typename It, typename K>
	It binary_search(It begin, It end, const K& key);

	template<typename It>
	void quick_sort(It begin, It end){
		if (end <= begin) return;
		It pivot{ begin };
		It middle{ begin + 1 };

		for (It i{ begin + 1 }; i != end; ++i) {
			if (*i < *pivot) {
				std::iter_swap(i, middle);
				++middle;
			}
		}
		std::iter_swap(begin, middle - 1);
		quick_sort(begin, middle - 1);
		quick_sort(middle, end);
	}

	template<typename Container>
	void quick_sort(const Container& container){
		quick_sort(container.begin(), container.end());
	}

	template<typename It, typename K>
	It binary_search(It begin, It end, const K& key){
		while (begin != end) {
			It middle{ begin + std::distance(begin, end) / 2 };

			if (*middle == key) return middle;

			if (*middle < key)
				begin = middle + 1;
			else
				end = middle - 1;
		}
		return end;
	}

}

#endif // !QUICK_SORT_HPP