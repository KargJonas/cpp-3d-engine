#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "./vec3.h"
#include "./triangle.h"

std::vector<Triangle> readFile(string filename) {
  using byte = std::uint8_t;
  using uint32 = std::uint32_t;

  vector<Triangle> triangles;

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

    // Copy the 4 bytes of triangle count data directly
    // into a uint32.
    uint32 triangleCount;
    std::memcpy(&triangleCount, raw.data() + 80, sizeof(uint32));

    // Each triangle takes up 50 bytes of data.
    const uint32 triangleDataSize = triangleCount * 50;

    // Read the rest of the file.
    std::vector<char> triangleData(triangleDataSize);
    const auto tdPointer = triangleData.data();
    file.read(tdPointer, triangleData.size());

    for (int iTriangle = 0; iTriangle < triangleCount; iTriangle++) {
      const auto triPointer = tdPointer + iTriangle * 50;
      Vec3 vectors[4];

      for (int iVec = 0; iVec < 4; iVec++) {
        const auto vecPointer = triPointer + iVec * 12;
        float x, y, z;

        std::memcpy(&x, vecPointer, 4);
        std::memcpy(&y, vecPointer + 4, 4);
        std::memcpy(&z, vecPointer + 8, 4);

        vectors[iVec] = Vec3(x, y, z);
      }

      triangles.push_back(Triangle(vectors));
    }
  }

  return triangles;
}
