#pragma once

#include <BNM/UnityStructures.hpp>
#include <BNM/Method.hpp>
#include <BNM/Field.hpp>
#include <BNM/Property.hpp>
#include <BNM/MethodBase.hpp>
#include <BNM/FieldBase.hpp>
#include <BNM/PropertyBase.hpp>
#include <BNM/Il2CppHeaders.hpp>

#include <GUI/GUISettings.hpp>
#include <XRInput.hpp>
#include <GUI/Button.hpp>
#include <GUI/GUIManager.hpp>
#include <GUI/Buttons.hpp>

using namespace BNM;
using namespace BNM::Structures;
using namespace BNM::Structures::Unity;
using namespace BNM::IL2CPP;

class ModGUI {
private:

public:

    static inline GUIManager* gui;
    static inline bool cooldown;
    static inline int maxPages;
    static inline float cooldownTime;
    static inline float rainbowCooldown;
    static inline int rainbowIndex;

    static inline Button backPage{
            .name = O("<- Back"),
            .method = []() { GUISettings::pageIndex--; },
            .type = "button"
    };

    static inline Button nextPage{
            .name = O("Next ->"),
            .method = []() { GUISettings::pageIndex++; },
            .type = "button"
    };

    static void Init();
    static void CorrectIndexLOL(std::vector<Button*>* modsReal);
    static Button* FindButton(const std::string& name);
    static void HandleMods();
    static void ChangeFont(Font* customFont);
    static void Update();
};
