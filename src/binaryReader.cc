#include "./vec3.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

std::vector<BYTE> readFile(string filename) {
  using byte = std::uint8_t;
  using uint32 = std::uint32_t;

  if (std::ifstream file{filename, std::ios::binary}) {

    // allocate a buffer for the header data
    std::vector<char> header(80);
    file.read(header.data(), header.size());

    std::vector<char> triangleCount(sizeof(uint32));
    file.read(triangleCount.data(), triangleCount.size());

    // number of bytes that were actually read
    const auto nread = file.gcount();

    std::cout << "Number of bytes read: " << nread << std::endl;
    std::vector<byte> bytes(header.begin(), header.begin() + nread);

    for (int i = 0; i < bytes.size(); i++) {
      byte b = bytes[i];

      std::cout << std::dec << i << '\t';
      std::cout << std::hex << int(b) << '\t';
      std::cout << b << std::endl;
    }
  }
}
