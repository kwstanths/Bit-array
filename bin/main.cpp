#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <algorithm>

#include "myBitarray.hpp"

void print(mns::bitarray::Bitarray1D& array){

      std::cout << std::endl;
      std::size_t bits = array.size();
      for(int i=0; i<bits; i++){
            std::cout << array.test(i);
      }
      std::cout << std::endl;
      for(int i=0; i<bits; i++){
            std::cout << array[i];
      }
      std::cout << std::endl;
      std::cout << array.to_string() << std::endl;
      std::cout << "Number of 1: " << array.count() << std::endl;
      std::cout << std::endl;
}

int main(int argc, char ** argv){

      mns::bitarray::Bitarray1D ar(10);
      ar.setAll(1);

      ar.set(1,0);
      ar.set(4,0);
      ar.set(9,0);
      print(ar);

      ar.setAll(1);
      ar.set(0,0);
      ar.set(3,0);
      ar.set(2,0);
      ar.set(7,0);
      ar.set(8,0);
      print(ar);

      ar.flip(0);
      ar.flip(1);
      ar.flip(2);
      ar.flip(4);
      print(ar);

      std::cout << std::endl;
      std::cout << ar[6] << std::endl;
      ar[6] = 0;
      std::cout << ar[6] << std::endl;
      ar[6] = 1;
      std::cout << ar[6] << std::endl;
      std::cout << std::endl;

      std::vector<mns::bitarray::Bitarray1D> ar1;
      ar1.push_back(mns::bitarray::Bitarray1D(5));
      ar1.push_back(mns::bitarray::Bitarray1D(4));
      std::cout << ar1[0][0] << std::endl;
      std::cout << ar1[1][2] << std::endl;
      std::cout << ar1[1][3] << std::endl;
      std::cout << std::endl;
      ar1[0][1] = 1;
      ar1[0][0] = ar1[1][1] = 1;
      std::cout << ar1[0][0] << std::endl;
      std::cout << ar1[0][1] << std::endl;
      std::cout << ar1[0][3] << std::endl;
      std::cout << ar1[1][0] << std::endl;
      std::cout << ar1[1][1] << std::endl;
      std::cout << ar1[1][3] << std::endl;
}
