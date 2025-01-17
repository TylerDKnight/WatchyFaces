#ifndef TRANSFORMATION_RULES_H
#define TRANSFORMATION_RULES_H

#include <array>

struct Rule {
    unsigned int original;
    unsigned int conjugated;
    unsigned int reflected;
    unsigned int minimum_rule;
};

const std::array<Rule, 256> transformationRules = {
    {255, 0, 255, 0},
    {127, 1, 127, 1},
    {191, 16, 247, 2},
    {63, 17, 119, 3},
    {223, 4, 223, 4},
    {95, 5, 95, 5},
    {159, 20, 215, 6},
    {31, 21, 87, 7},
    {239, 64, 253, 8},
    {111, 65, 125, 9},
    {175, 80, 245, 10},
    {47, 81, 117, 11},
    {207, 68, 221, 12},
    {79, 69, 93, 13},
    {143, 84, 213, 14},
    {15, 85, 85, 15},
    {247, 2, 191, 2},
    {119, 3, 63, 3},
    {183, 18, 183, 18},
    {55, 19, 55, 19},
    {215, 6, 159, 6},
    {87, 7, 31, 7},
    {151, 22, 151, 22},
    {23, 23, 23, 23},
    {231, 66, 189, 24},
    {103, 67, 61, 25},
    {167, 82, 181, 26},
    {39, 83, 53, 27},
    {199, 70, 157, 28},
    {71, 71, 29, 29},
    {135, 86, 149, 30},
    {7, 87, 21, 7},
    {251, 32, 251, 32},
    {123, 33, 123, 33},
    {187, 48, 243, 34},
    {59, 49, 115, 35},
    {219, 36, 219, 36},
    {91, 37, 91, 37},
    {155, 52, 211, 38},
    {27, 53, 83, 27},
    {235, 96, 249, 40},
    {107, 97, 121, 41},
    {171, 112, 241, 42},
    {43, 113, 113, 43},
    {203, 100, 217, 44},
    {75, 101, 89, 45},
    {139, 116, 209, 46},
    {11, 117, 81, 11},
    {243, 34, 187, 34},
    {115, 35, 59, 35},
    {179, 50, 179, 50},
    {51, 51, 51, 51},
    {211, 38, 155, 38},
    {83, 39, 27, 27},
    {147, 54, 147, 54},
    {19, 55, 19, 19},
    {227, 98, 185, 56},
    {99, 99, 57, 57},
    {163, 114, 177, 58},
    {35, 115, 49, 35},
    {195, 102, 153, 60},
    {67, 103, 25, 25},
    {131, 118, 145, 62},
    {3, 119, 17, 3},
    {253, 8, 239, 8},
    {125, 9, 111, 9},
    {189, 24, 231, 24},
    {61, 25, 103, 25},
    {221, 12, 207, 12},
    {93, 13, 79, 13},
    {157, 28, 199, 28},
    {29, 29, 71, 29},
    {237, 72, 237, 72},
    {109, 73, 109, 73},
    {173, 88, 229, 74},
    {45, 89, 101, 45},
    {205, 76, 205, 76},
    {77, 77, 77, 77},
    {141, 92, 197, 78},
    {13, 93, 69, 13},
    {245, 10, 175, 10},
    {117, 11, 47, 11},
    {181, 26, 167, 26},
    {53, 27, 39, 27},
    {213, 14, 143, 14},
    {85, 15, 15, 15},
    {149, 30, 135, 30},
    {21, 31, 7, 7},
    {229, 74, 173, 74},
    {101, 75, 45, 45},
    {165, 90, 165, 90},
    {37, 91, 37, 37},
    {197, 78, 141, 78},
    {69, 79, 13, 13},
    {133, 94, 133, 94},
    {5, 95, 5, 5},
    {249, 40, 235, 40},
    {121, 41, 107, 41},
    {185, 56, 227, 56},
    {57, 57, 99, 57},
    {217, 44, 203, 44},
    {89, 45, 75, 45},
    {153, 60, 195, 60},
    {25, 61, 67, 25},
    {233, 104, 233, 104},
    {105, 105, 105, 105},
    {169, 120, 225, 106},
    {41, 121, 97, 41},
    {201, 108, 201, 108},
    {73, 109, 73, 73},
    {137, 124, 193, 110},
    {9, 125, 65, 9},
    {241, 42, 171, 42},
    {113, 43, 43, 43},
    {177, 58, 163, 58},
    {49, 59, 35, 35},
    {209, 46, 139, 46},
    {81, 47, 11, 11},
    {145, 62, 131, 62},
    {17, 63, 3, 3},
    {225, 106, 169, 106},
    {97, 107, 41, 41},
    {161, 122, 161, 122},
    {33, 123, 33, 33},
    {193, 110, 137, 110},
    {65, 111, 9, 9},
    {129, 126, 129, 126},
    {1, 127, 1, 1},
    {254, 128, 254, 128},
    {126, 129, 126, 126},
    {190, 144, 246, 130},
    {62, 145, 118, 62},
    {222, 132, 222, 132},
    {94, 133, 94, 94},
    {158, 148, 214, 134},
    {30, 149, 86, 30},
    {238, 192, 252, 136},
    {110, 193, 124, 110},
    {174, 208, 244, 138},
    {46, 209, 116, 46},
    {206, 196, 220, 140},
    {78, 197, 92, 78},
    {142, 212, 212, 142},
    {14, 213, 84, 14},
    {246, 130, 190, 130},
    {118, 131, 62, 62},
    {182, 146, 182, 146},
    {54, 147, 54, 54},
    {214, 134, 158, 134},
    {86, 135, 30, 30},
    {150, 150, 150, 150},
    {22, 151, 22, 22},
    {230, 194, 188, 152},
    {102, 195, 60, 60},
    {166, 210, 180, 154},
    {38, 211, 52, 38},
    {198, 198, 156, 156},
    {70, 199, 28, 28},
    {134, 214, 148, 134},
    {6, 215, 20, 6},
    {250, 160, 250, 160},
    {122, 161, 122, 122},
    {186, 176, 242, 162},
    {58, 177, 114, 58},
    {218, 164, 218, 164},
    {90, 165, 90, 90},
    {154, 180, 210, 154},
    {26, 181, 82, 26},
    {234, 224, 248, 168},
    {106, 225, 120, 106},
    {170, 240, 240, 170},
    {42, 241, 112, 42},
    {202, 228, 216, 172},
    {74, 229, 88, 74},
    {138, 244, 208, 138},
    {10, 245, 80, 10},
    {242, 162, 186, 162},
    {114, 163, 58, 58},
    {178, 178, 178, 178},
    {50, 179, 50, 50},
    {210, 166, 154, 154},
    {82, 167, 26, 26},
    {146, 182, 146, 146},
    {18, 183, 18, 18},
    {226, 226, 184, 184},
    {98, 227, 56, 56},
    {162, 242, 176, 162},
    {34, 243, 48, 34},
    {194, 230, 152, 152},
    {66, 231, 24, 24},
    {130, 246, 144, 130},
    {2, 247, 16, 2},
    {252, 136, 238, 136},
    {124, 137, 110, 110},
    {188, 152, 230, 152},
    {60, 153, 102, 60},
    {220, 140, 206, 140},
    {92, 141, 78, 78},
    {156, 156, 198, 156},
    {28, 157, 70, 28},
    {236, 200, 236, 200},
    {108, 201, 108, 108},
    {172, 216, 228, 172},
    {44, 217, 100, 44},
    {204, 204, 204, 204},
    {76, 205, 76, 76},
    {140, 220, 196, 140},
    {12, 221, 68, 12},
    {244, 138, 174, 138},
    {116, 139, 46, 46},
    {180, 154, 166, 154},
    {52, 155, 38, 38},
    {212, 142, 142, 142},
    {84, 143, 14, 14},
    {148, 158, 134, 134},
    {20, 159, 6, 6},
    {228, 202, 172, 172},
    {100, 203, 44, 44},
    {164, 218, 164, 164},
    {36, 219, 36, 36},
    {196, 206, 140, 140},
    {68, 207, 12, 12},
    {132, 222, 132, 132},
    {4, 223, 4, 4},
    {248, 168, 234, 168},
    {120, 169, 106, 106},
    {184, 184, 226, 184},
    {56, 185, 98, 56},
    {216, 172, 202, 172},
    {88, 173, 74, 74},
    {152, 188, 194, 152},
    {24, 189, 66, 24},
    {232, 232, 232, 232},
    {104, 233, 104, 104},
    {168, 248, 224, 168},
    {40, 249, 96, 40},
    {200, 236, 200, 200},
    {72, 237, 72, 72},
    {136, 252, 192, 136},
    {8, 253, 64, 8},
    {240, 170, 170, 170},
    {112, 171, 42, 42},
    {176, 186, 162, 162},
    {48, 187, 34, 34},
    {208, 174, 138, 138},
    {80, 175, 10, 10},
    {144, 190, 130, 130},
    {16, 191, 2, 2},
    {224, 234, 168, 168},
    {96, 235, 40, 40},
    {160, 250, 160, 160},
    {32, 251, 32, 32},
    {192, 238, 136, 136},
    {64, 239, 8, 8},
    {128, 254, 128, 128},
    {0, 255, 0, 0},
};

#endif // TRANSFORMATION_RULES_H