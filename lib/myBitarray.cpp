#include "myBitarray.hpp"

namespace mns{

namespace bitarray{

      Bitarray1D::Bitarray1D(std::size_t bits){
            if (bits == 0) throw std::invalid_argument("Can't initialize zero size array");

            bits_ = bits;
            elem_size_ = uint_size;

            elements_ = (bits_ + elem_size_ -1) / elem_size_;
            array_.resize(elements_);
      }

      std::size_t Bitarray1D::size() const {
            return bits_;
      }

      std::size_t Bitarray1D::count() const {
            std::size_t total_count = 0;
            for(int i=0; i<bits_; i++)
                  total_count += test(i);

            return total_count;
      }

      void Bitarray1D::setAll(Elem value){
            if (value != 1 && value != 0) throw std::invalid_argument("Value must be 1 or 0");
            std::fill(array_.begin(), array_.end(), value*(pow(2,elem_size_)-1));
      }

      void Bitarray1D::set(Elem index, bool value){
            if (index >= bits_) throw std::out_of_range("Index out of range");

            int elem = element(index);
            int bit = offset(index);

            if (value == 0){
                  Elem and_var = pow(2, 8*elem_size_) - 1 - pow(2, bit);
                  array_[elem] = array_[elem] & and_var;
                  return;
            }

            if (value == 1){
                  Elem or_var = pow(2,bit);
                  array_[elem] = array_[elem] | or_var;
                  return;
            }

      }

      Bitarray1D::Elem Bitarray1D::test(Elem index) const {
            if (index >= bits_) throw std::out_of_range("Index out of range");

            int elem = element(index);
            int bit = offset(index);

            return (array_[elem] >> bit) & 1u ;
      }

      Bitarray1D::Bit Bitarray1D::operator [] (Elem index) {
            if (index >= bits_) throw std::out_of_range("Index out of range");

            return Bit(*this, index);
      }

      void Bitarray1D::flip(Elem index) {
            if (index >= bits_) throw std::out_of_range("Index out of range");

            int elem = element(index);
            int bit = offset(index);

            Elem xor_var = pow(2,bit);
            array_[elem] = array_[elem] ^ xor_var;
            return;
      }

      std::string Bitarray1D::to_string() const {
            std::string acc = "";
            for(int i=0; i<bits_; i++)
                  acc += std::to_string(test(i));

            return acc;
      }

      std::size_t Bitarray1D::element(std::size_t index) const {
            return index / elem_size_;
      }

      std::size_t Bitarray1D::offset(std::size_t index) const {
            return index % elem_size_;
      }

      Bitarray1D::Elem Bitarray1D::Bit::getValue() const {
            return array_.test(index_);
      }

      Bitarray1D::Bit& Bitarray1D::Bit::operator [] (Elem value) {
            return *this;
      }

      Bitarray1D::Bit& Bitarray1D::Bit::operator = (Elem value){
            array_.set(index_, value);
            return *this;
      }

      Bitarray1D::Bit& Bitarray1D::Bit::operator = (const Bit& other){
            array_.set(index_, other.getValue());
      }

      std::ostream& operator<<(std::ostream& os, const Bitarray1D::Bit& bit){
            os << bit.getValue();
            return os;
      }

}

}
