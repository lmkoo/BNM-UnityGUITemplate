#pragma once

#include <BNM/UnityStructures.hpp>
#include <BNM/Il2CppHeaders.hpp>

using namespace BNM;
using namespace BNM::Structures;
using namespace BNM::Structures::Unity;
using namespace BNM::IL2CPP;

class GUISettings {
public:
    static int categoryIndex;
    static int cursorIndex;
    static int pageIndex;

    static void Init() {
        categoryIndex = 0;
        pageIndex = 0;
        cursorIndex = 0;
    }

    static void Reset() {
        categoryIndex = 0;
        pageIndex = 0;
        cursorIndex = 0;
    }
};