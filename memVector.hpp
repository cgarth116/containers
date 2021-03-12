#pragma once

#include <stdexcept>
#include <memory>

template < typename value_type,
		typename allocator_type,
		typename size_type >
class memVector {
public:
	static
	void	destruct(value_type * const begin,
			   		const value_type * const end,
			   		allocator_type & alloc) {
		if (begin == end) {
			return;
		}
		alloc.destroy(begin);
		destruct(begin + 1, end, alloc);
	}
	static
	value_type *	realloc(value_type * const sourceArray,
							   const size_type realSize,
							   const size_type prevCapacity,
							   const size_type newCapacity,
							   allocator_type & alloc) throw(std::bad_alloc) {
		value_type * const newMemory = alloc.allocate(newCapacity);
		std::memmove(newMemory, sourceArray, realSize * sizeof(value_type));
		alloc.deallocate(sourceArray, prevCapacity);
		return newMemory;
	}
	inline static
	void	deleteAll(value_type * const sourceArray,
				  	const size_type realSize,
				  	const size_type capacity,
				  	allocator_type & alloc) {
		destruct(sourceArray, sourceArray + realSize, alloc);
		alloc.deallocate(sourceArray, capacity);
	}
};