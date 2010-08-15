/* Copyright (C) 2005-2010 Valeriy Argunov (nporep AT mail DOT ru) */
/*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "coding.h"
#include "text.h"

unsigned char qspCP1251ToKOI8RTable[] =
{
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x9A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xB3, 0xBF, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x9C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x9E, 0xA3, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0xE1, 0xE2, 0xF7, 0xE7, 0xE4, 0xE5, 0xF6, 0xFA, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0,
	0xF2, 0xF3, 0xF4, 0xF5, 0xE6, 0xE8, 0xE3, 0xFE, 0xFB, 0xFD, 0xFF, 0xF9, 0xF8, 0xFC, 0xE0, 0xF1,
	0xC1, 0xC2, 0xD7, 0xC7, 0xC4, 0xC5, 0xD6, 0xDA, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0,
	0xD2, 0xD3, 0xD4, 0xD5, 0xC6, 0xC8, 0xC3, 0xDE, 0xDB, 0xDD, 0xDF, 0xD9, 0xD8, 0xDC, 0xC0, 0xD1
};

wchar_t qspKOI8RToUnicodeTable[] =
{
	0x2500, 0x2502, 0x250C, 0x2510, 0x2514, 0x2518, 0x251C, 0x2524,
	0x252C, 0x2534, 0x253C, 0x2580, 0x2584, 0x2588, 0x258C, 0x2590,
	0x2591, 0x2592, 0x2593, 0x2320, 0x25A0, 0x2219, 0x221A, 0x2248,
	0x2264, 0x2265, 0x00A0, 0x2321, 0x00B0, 0x00B2, 0x00B7, 0x00F7,
	0x2550, 0x2551, 0x2552, 0x0451, 0x2553, 0x2554, 0x2555, 0x2556,
	0x2557, 0x2558, 0x2559, 0x255A, 0x255B, 0x255C, 0x255D, 0x255E,
	0x255F, 0x2560, 0x2561, 0x0401, 0x2562, 0x2563, 0x2564, 0x2565,
	0x2566, 0x2567, 0x2568, 0x2569, 0x256A, 0x256B, 0x256C, 0x00A9,
	0x044E, 0x0430, 0x0431, 0x0446, 0x0434, 0x0435, 0x0444, 0x0433,
	0x0445, 0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E,
	0x043F, 0x044F, 0x0440, 0x0441, 0x0442, 0x0443, 0x0436, 0x0432,
	0x044C, 0x044B, 0x0437, 0x0448, 0x044D, 0x0449, 0x0447, 0x044A,
	0x042E, 0x0410, 0x0411, 0x0426, 0x0414, 0x0415, 0x0424, 0x0413,
	0x0425, 0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E,
	0x041F, 0x042F, 0x0420, 0x0421, 0x0422, 0x0423, 0x0416, 0x0412,
	0x042C, 0x042B, 0x0417, 0x0428, 0x042D, 0x0429, 0x0427, 0x042A
};

wchar_t qspCP1251ToUnicodeTable[] =
{
	0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
	0x20AC, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
	0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
	0x0020, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
	0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
	0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
	0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
	0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
	0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
	0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
	0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
	0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
	0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
	0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
	0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
	0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F
};

unsigned char qspCP1251ToUpperTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x81, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x80, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x8A, 0x9B, 0x8C, 0x8D, 0x8E, 0x8F,
	0xA0, 0xA1, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xB2, 0xA5, 0xB5, 0xB6, 0xB7, 0xA8, 0xB9, 0xAA, 0xBB, 0xA3, 0xBD, 0xBD, 0xAF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF
};

unsigned char qspCP1251ToLowerTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x90, 0x83, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x9A, 0x8B, 0x9C, 0x9D, 0x9E, 0x9F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA2, 0xA2, 0xBC, 0xA4, 0xB4, 0xA6, 0xA7, 0xB8, 0xA9, 0xBA, 0xAB, 0xAC, 0xAD, 0xAE, 0xBF,
	0xB0, 0xB1, 0xB3, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBE, 0xBE, 0xBF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

unsigned char qspKOI8RToUpperTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA1, 0xA2, 0xB3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

unsigned char qspKOI8RToLowerTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xA3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF
};

unsigned char qspCP1251OrderTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40,
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
	0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60,
	0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70,
	0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80,
	0x91, 0x92, 0xF2, 0xE0, 0xF5, 0xF9, 0xF6, 0xF7, 0xFD, 0xFA, 0x98, 0xFB, 0x99, 0x9B, 0x9A, 0x9D,
	0xDF, 0xF0, 0xF1, 0xF3, 0xF4, 0xF8, 0xEE, 0xEF, 0x20, 0xFF, 0xE6, 0xFC, 0xE7, 0xE9, 0xE8, 0xEB,
	0x81, 0x9C, 0xEA, 0x97, 0x82, 0xEC, 0x83, 0x84, 0x90, 0x85, 0x93, 0x86, 0x87, 0x88, 0x89, 0x96,
	0x8A, 0x8B, 0x95, 0xE3, 0xED, 0x8C, 0x8D, 0x8E, 0xDE, 0xFE, 0xE1, 0x8F, 0xE5, 0x94, 0xE2, 0xE4,
	0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD,
	0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD,
	0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD,
	0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD
};

unsigned char qspKOI8ROrderTable[] =
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB,
	0xFC, 0xFD, 0xFE, 0xCD, 0xFF, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0x80, 0xCE, 0x82, 0x83, 0x84, 0x85,
	0xDA, 0xDB, 0xDC, 0xC7, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8,
	0xE9, 0xEA, 0xEB, 0x86, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0x81,
	0xC5, 0xA7, 0xA8, 0xBD, 0xAB, 0xAC, 0xBB, 0xAA, 0xBC, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5,
	0xB6, 0xC6, 0xB7, 0xB8, 0xB9, 0xBA, 0xAD, 0xA9, 0xC3, 0xC2, 0xAE, 0xBF, 0xC4, 0xC0, 0xBE, 0xC1,
	0xA5, 0x87, 0x88, 0x9D, 0x8B, 0x8C, 0x9B, 0x8A, 0x9C, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95,
	0x96, 0xA6, 0x97, 0x98, 0x99, 0x9A, 0x8D, 0x89, 0xA3, 0xA2, 0x8E, 0x9F, 0xA4, 0xA0, 0x9E, 0xA1
};

static int qspUCS2StrLen(char *);
static char *qspUCS2StrStr(char *, char *);
static char qspDirectConvertSB(char, unsigned char *);
static char qspReverseConvertSB(char, unsigned char *);
static wchar_t qspDirectConvertUC(char, wchar_t *);
static char qspReverseConvertUC(wchar_t, wchar_t *);
static char *qspQSPToGameString(QSP_CHAR *, QSP_BOOL, QSP_BOOL);

static int qspUCS2StrLen(char *str)
{
	unsigned short *ptr = (unsigned short *)str;
	while (*ptr) ++ptr;
	return (int)(ptr - (unsigned short *)str);
}

static char *qspUCS2StrStr(char *str, char *subStr)
{
	unsigned short *s1, *s2, *cp = (unsigned short *)str;
	while (*cp)
	{
		s1 = cp;
		s2 = (unsigned short *)subStr;
		while (*s1 && *s2 && !((int)*s1 - *s2))
			++s1, ++s2;
		if (!(*s2)) return (char *)cp;
		++cp;
	}
	return 0;
}

int qspStrCmpSB(char *s1, char *s2, unsigned char *table)
{
	int ret = 0;
	while (!(ret = (int)table[*(unsigned char *)s1] - table[*(unsigned char *)s2]) && *s2)
		++s1, ++s2;
	return ret;
}

static char qspDirectConvertSB(char ch, unsigned char *table)
{
	unsigned char ch2 = (unsigned char)ch;
	return (ch2 >= 0x80 ? table[ch2 - 0x80] : ch);
}

static char qspReverseConvertSB(char ch, unsigned char *table)
{
	int i;
	unsigned char ch2 = (unsigned char)ch;
	if (ch2 < 0x80) return ch;
	for (i = 127; i >= 0; --i)
		if (table[i] == ch2) return (char)(i + 0x80);
	return 0x20;
}

static wchar_t qspDirectConvertUC(char ch, wchar_t *table)
{
	unsigned char ch2 = (unsigned char)ch;
	return (ch2 >= 0x80 ? table[ch2 - 0x80] : ch);
}

static char qspReverseConvertUC(wchar_t ch, wchar_t *table)
{
	int i;
	if (ch < 0x80) return (char)ch;
	for (i = 127; i >= 0; --i)
		if (table[i] == ch) return (char)(i + 0x80);
	return 0x20;
}

QSP_CHAR *qspCodeReCode(QSP_CHAR *str, QSP_BOOL isCode)
{
	int len = qspStrLen(str);
	QSP_CHAR ch, *buf = (QSP_CHAR *)malloc((len + 1) * sizeof(QSP_CHAR));
	buf[len] = 0;
	if (isCode)
	{
		while (--len >= 0)
		{
			ch = str[len];
			if (ch == QSP_CODREMOV)
				ch = (QSP_CHAR)-QSP_CODREMOV;
			else
				ch -= QSP_CODREMOV;
			buf[len] = ch;
		}
	}
	else
	{
		while (--len >= 0)
		{
			ch = str[len];
			if (ch == (QSP_CHAR)-QSP_CODREMOV)
				ch = QSP_CODREMOV;
			else
				ch += QSP_CODREMOV;
			buf[len] = ch;
		}
	}
	return buf;
}

char *qspFromQSPString(QSP_CHAR *s)
{
	#ifdef _FLASH
		return qspW2C(s);
	#else
		int len = QSP_WCSTOMBSLEN(s) + 1;
		char *ret = (char *)malloc(len);
		QSP_WCSTOMBS(ret, s, len);
		return ret;
	#endif
}

static char *qspQSPToGameString(QSP_CHAR *s, QSP_BOOL isUCS2, QSP_BOOL isCode)
{
	unsigned short uCh, *ptr;
	int len = qspStrLen(s);
	char ch, *ret = (char *)malloc((len + 1) * (isUCS2 ? 2 : 1));
	if (isUCS2)
	{
		ptr = (unsigned short *)ret;
		ptr[len] = 0;
		if (isCode)
		{
			while (--len >= 0)
			{
				uCh = QSP_BTOWC(s[len]);
				if (uCh == QSP_CODREMOV)
					uCh = (unsigned short)-QSP_CODREMOV;
				else
					uCh -= QSP_CODREMOV;
				ptr[len] = QSP_FIXBYTESORDER(uCh);
			}
		}
		else
		{
			while (--len >= 0)
			{
				uCh = QSP_BTOWC(s[len]);
				ptr[len] = QSP_FIXBYTESORDER(uCh);
			}
		}
	}
	else
	{
		ret[len] = 0;
		if (isCode)
		{
			while (--len >= 0)
			{
				ch = QSP_FROM_OS_CHAR(s[len]);
				if (ch == QSP_CODREMOV)
					ch = -QSP_CODREMOV;
				else
					ch -= QSP_CODREMOV;
				ret[len] = ch;
			}
		}
		else
		{
			while (--len >= 0)
				ret[len] = QSP_FROM_OS_CHAR(s[len]);
		}
	}
	return ret;
}

QSP_CHAR *qspGameToQSPString(char *s, QSP_BOOL isUCS2, QSP_BOOL isCoded)
{
	char ch;
	unsigned short uCh, *ptr;
	int len = (isUCS2 ? qspUCS2StrLen(s) : (int)strlen(s));
	QSP_CHAR *ret = (QSP_CHAR *)malloc((len + 1) * sizeof(QSP_CHAR));
	ret[len] = 0;
	if (isUCS2)
	{
		ptr = (unsigned short *)s;
		if (isCoded)
		{
			while (--len >= 0)
			{
				uCh = QSP_FIXBYTESORDER(ptr[len]);
				if (uCh == (unsigned short)-QSP_CODREMOV)
					uCh = QSP_CODREMOV;
				else
					uCh += QSP_CODREMOV;
				ret[len] = QSP_WCTOB(uCh);
			}
		}
		else
		{
			while (--len >= 0)
			{
				uCh = QSP_FIXBYTESORDER(ptr[len]);
				ret[len] = QSP_WCTOB(uCh);
			}
		}
	}
	else
	{
		if (isCoded)
		{
			while (--len >= 0)
			{
				ch = s[len];
				if (ch == -QSP_CODREMOV)
					ch = QSP_CODREMOV;
				else
					ch += QSP_CODREMOV;
				ret[len] = QSP_TO_OS_CHAR(ch);
			}
		}
		else
		{
			while (--len >= 0)
				ret[len] = QSP_TO_OS_CHAR(s[len]);
		}
	}
	return ret;
}

int qspSplitGameStr(char *str, QSP_BOOL isUCS2, QSP_CHAR *delim, char ***res)
{
	char *delimStr, *newStr, **ret, *found, *curPos = str;
	int charSize, delimSize, allocChars, count = 0, bufSize = 8;
	charSize = (isUCS2 ? 2 : 1);
	delimSize = qspStrLen(delim) * charSize;
	delimStr = qspQSPToGameString(delim, isUCS2, QSP_FALSE);
	found = (isUCS2 ? qspUCS2StrStr(str, delimStr) : strstr(str, delimStr));
	ret = (char **)malloc(bufSize * sizeof(char *));
	while (found)
	{
		allocChars = (int)(found - curPos);
		newStr = (char *)malloc(allocChars + charSize);
		memcpy(newStr, curPos, allocChars);
		if (isUCS2)
			*((unsigned short *)(newStr + allocChars)) = 0;
		else
			newStr[allocChars] = 0;
		if (++count > bufSize)
		{
			bufSize <<= 1;
			ret = (char **)realloc(ret, bufSize * sizeof(char *));
		}
		ret[count - 1] = newStr;
		curPos = found + delimSize;
		found = (isUCS2 ? qspUCS2StrStr(curPos, delimStr) : strstr(curPos, delimStr));
	}
	free(delimStr);
	allocChars = (isUCS2 ? (qspUCS2StrLen(curPos) + 1) * charSize : (int)strlen(curPos) + 1);
	newStr = (char *)malloc(allocChars);
	memcpy(newStr, curPos, allocChars);
	if (++count > bufSize)
		ret = (char **)realloc(ret, count * sizeof(char *));
	ret[count - 1] = newStr;
	*res = ret;
	return count;
}

int qspReCodeGetIntVal(QSP_CHAR *val)
{
	int num;
	QSP_CHAR *temp = qspCodeReCode(val, QSP_FALSE);
	num = qspStrToNum(temp, 0);
	free(temp);
	return num;
}

int qspCodeWriteIntVal(QSP_CHAR **s, int len, int val, QSP_BOOL isCode)
{
	QSP_CHAR buf[12], *temp;
	qspNumToStr(buf, val);
	if (isCode)
	{
		temp = qspCodeReCode(buf, QSP_TRUE);
		len = qspAddText(s, temp, len, -1, QSP_FALSE);
		free(temp);
	}
	else
		len = qspAddText(s, buf, len, -1, QSP_FALSE);
	return qspAddText(s, QSP_STRSDELIM, len, QSP_LEN(QSP_STRSDELIM), QSP_FALSE);
}

int qspCodeWriteVal(QSP_CHAR **s, int len, QSP_CHAR *val, QSP_BOOL isCode)
{
	QSP_CHAR *temp;
	if (val)
	{
		if (isCode)
		{
			temp = qspCodeReCode(val, QSP_TRUE);
			len = qspAddText(s, temp, len, -1, QSP_FALSE);
			free(temp);
		}
		else
			len = qspAddText(s, val, len, -1, QSP_FALSE);
	}
	return qspAddText(s, QSP_STRSDELIM, len, QSP_LEN(QSP_STRSDELIM), QSP_FALSE);
}
