#ifndef __BITARRAY_HPP__
#define __BITARRAY_HPP__

#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <string>
#include <stdexcept>

namespace mns{

namespace bitarray {

	static const std::size_t uint_size = sizeof(unsigned int);
	static const std::size_t usint_size = sizeof(unsigned short int);

	class Bitarray1D {
		using Elem = unsigned int;
	public:
		class Bit{
		private:
			Bitarray1D& array_;
			Elem index_;

		public:
			Bit(Bitarray1D& array, Elem index): array_(array), index_(index){}

			Elem getValue() const;

			Bit& operator [] (Elem value);

			Bit& operator = (Elem value);

			Bit& operator = (const Bit& other);

			friend std::ostream& operator<<(std::ostream& os, const Bit& bit);
		};

	private:
		std::vector<Elem> array_;
		std::size_t elements_;
		std::size_t bits_;
		std::size_t elem_size_;

	public:
		Bitarray1D(std::size_t bits);

		~Bitarray1D() = default;

		std::size_t size() const;

		std::size_t count() const;

		void setAll(Elem value);

		void set(Elem index, bool value);

		Elem test(Elem index) const;

		Bit operator [](Elem index);

		void flip(Elem index);

		std::string to_string() const;

	private:
		std::size_t element(std::size_t index) const;

		std::size_t offset(std::size_t index) const;

	};

}

}

#endif
