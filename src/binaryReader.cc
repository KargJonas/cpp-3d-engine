#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "./vec3.h"
#include "./triangle.h"

std::vector<BYTE> readFile(string filename) {
  using byte = std::uint8_t;
  using uint32 = std::uint32_t;

  if (std::ifstream file{filename, std::ios::binary}) {

    // Allocate a buffer for all of the file data
    // We read exactly 84 bytes because the first 80 bytes
    // of any STL file contains the header and the next
    // 4 bytes contain an unsigned int32 containing the
    // number of triangles.
    std::vector<char> raw(84);
    file.read(raw.data(), raw.size());

    // Load the header into the header buffer and the
    // triangle count into the triangle count buffer.
    std::vector<byte> header(raw.begin(), raw.begin() + 80);
    std::vector<byte> triangleCountData(raw.begin() + 80, raw.begin() + 84);

    // Copy the data stored.
    uint32 triangleCount;
    std::memcpy(&triangleCount, triangleCountData.data(), sizeof(uint32));

    // Each triangle takes up 50 bytes of data.
    const uint32 triangleDataSize = triangleCount * 50;

    // Read the rest of the file.
    std::vector<char> triangleData(triangleDataSize);
    file.read(triangleData.data(), triangleData.size());

    vector<Triangle> triangles;

    for (int i = 0; i < triangleData.size(); i++) {
      byte b = triangleData[i];

      std::cout << std::dec << i << '\t';
      std::cout << std::hex << int(b) << '\t';
      std::cout << b << std::endl;
    }
  }
}
