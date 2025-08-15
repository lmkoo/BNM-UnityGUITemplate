#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <GUIInclude.hpp>
#include <BNMIncludes.hpp>

//Example for including Mod files
//#include <Mods/ModPage.hpp>

#include <NotiLib/NotiLib.hpp>
#include <Mods/ModSettings.hpp>
using namespace std;
class Buttons {
private:
    inline static void ChangeCat(int i) {
        GUISettings::categoryIndex = i;
        GUISettings::pageIndex = 0;
        GUISettings::cursorIndex = 0;
    }

public:
    inline static std::vector<std::vector<Button>> buttons = {
            {
                Button{ .name = "Settings", .method = []() { ChangeCat(1); }, .type = "button",},
                Button{ .name = "PlaceHolder", .method = []() { ChangeCat(2); }, .type = "button"},
                Button{ .name = "PlaceHolder", .method = []() { ChangeCat(3); }, .type = "button"},
                Button{ .name = "PlaceHolder", .method = []() { ChangeCat(4); }, .type = "button"},
                Button{ .name = "PlaceHolder", .method = []() { ChangeCat(5); }, .type = "button"},
                Button{ .name = "PlaceHolder", .method = []() { ChangeCat(6); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button{ .name = "Menu Theme", .type = "slider", .maxSlide = 6, .slideNames = std::vector<std::string>{ "default", "rainbow", "red", "blue", "lmko", "mre", "jae" }},
                //Only for Gorilla Tag
                Button{ .name = "Menu Font", .type = "slider", .maxSlide = 1, .slideNames = std::vector<std::string>{ "default", "COC"}},
            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                //Toggle Button
                //Button{ .name = "Custom Fly", .method = Movement::FlyMethod, .tooltip = "Custom Fly",},
                //Toggle Button that has enabled and disable 
                //Made for mods that need to return to a dafault value
                //Button{ .name = "Steam Longarms", .enableMethod = []() {Movement::Longarms(true); }, .disableMethod = []() { Movement::Longarms(false); } , .type = "toggle",.tooltip = "Toggles Longarms"},
                //Single Action Button
                //Button{ .name = "Join Room", .method = []() { PhotonMods::JoinRoom(""); }, .type = "button"},

                //If youre doing a method with parameters add
                // []() {ExampleMethod("ExampleParameters");} 
                //As the .method
            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(5); }, .type = "button"},

            },
            {
                Button{ .name = "Back", .method = []() { ChangeCat(7); }, .type = "button"},

            },
    };
};

