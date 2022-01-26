#include "../lib/rawdraw_sf.h"
typedef unsigned char BYTE;

uint32_t b(BYTE b)
{ return (b << 24) + (b << 16) + (b << 8) + 0xff; }

uint32_t rgb(BYTE r, BYTE g, BYTE b)
{ return (r << 24) + (g << 16) + (b << 8) + 0xff; }

uint32_t rgba(BYTE r, BYTE g, BYTE b, BYTE a)
{ return (r << 24) + (g << 16) + (b << 8) + a; }