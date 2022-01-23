#include "../lib/rawdraw_sf.h"

uint32_t b(unsigned char b)
{ return (b << 24) + (b << 16) + (b << 8) + 0xff; }

uint32_t rgb(unsigned char r, unsigned char g, unsigned char b)
{ return (r << 24) + (g << 16) + (b << 8) + 0xff; }

uint32_t rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{ return (r << 24) + (g << 16) + (b << 8) + a; }