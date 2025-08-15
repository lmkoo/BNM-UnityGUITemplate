#pragma once
#include <GUIInclude.hpp>
#include <BNMIncludes.hpp>
#include <GUI/ModGUI.hpp>
//#include <NotiLib/NotiLib.hpp

using namespace BNM;
using namespace BNM::Structures;
using namespace BNM::Structures::Unity;
using namespace BNM::IL2CPP;

//Don't need to mess with unless you wanna change the font or dockpos
void ModGUI::Init() {
    gui = new GUIManager();
    gui->Init(GameObject::Find("Main Camera")->GetTransform(), TextAnchor::UpperRight, nullptr);
    BNM_LOG_INFO("GUI initialized.");
}

void ModGUI::CorrectIndexLOL(std::vector<Button*>* modsReal) {
    int max = (int)std::ceil((float)Buttons::buttons[GUISettings::categoryIndex].size() / 8.0f) - 1;
    maxPages = std::max(0, max);

    if (GUISettings::pageIndex < 0) GUISettings::pageIndex = maxPages;
    if (GUISettings::pageIndex > maxPages) GUISettings::pageIndex = 0;

    if (GUISettings::cursorIndex < 0) GUISettings::cursorIndex = (int)modsReal->size() - 1;
    if (GUISettings::cursorIndex > (int)modsReal->size() - 1) GUISettings::cursorIndex = 0;
}

Button* ModGUI::FindButton(const std::string& name) {
    for (auto& c : Buttons::buttons) {
        for (auto& b : c) {
            if (b.name == name) {
                return &b;
            }
        }
    }
    return nullptr;
}

void ModGUI::HandleMods() {
    for (auto& c : Buttons::buttons) {
        for (auto& b : c) {
            if (b.enabled && b.method) {
                b.method();
            }
        }
    }
}

void ModGUI::ChangeFont(Font* customFont){
    gui->Destroy();
    gui->Init(GameObject::Find("Main Camera")->GetTransform(), TextAnchor::UpperRight, customFont);
}

void ModGUI::Update() {
    HandleMods();

    Class Time = Class("UnityEngine", "Time");
    Property<float> time = Time.GetProperty("time");

    bool condition = XRInput::GetBoolFeature(BoolFeature::Primary2DAxisClick, Controller::Left);
    bool click = XRInput::GetBoolFeature(BoolFeature::Primary2DAxisClick, Controller::Right);
    Vector2 stick = XRInput::GetVector2Feature(Vector2Feature::Primary2DAxis, Controller::Right);

    std::vector<Button*> modz;
    int startIndex = GUISettings::pageIndex * 8;
    int endIndex = std::ranges::clamp(startIndex + 8, 0, (int)Buttons::buttons[GUISettings::categoryIndex].size());

    for (int i = startIndex; i < endIndex; ++i) {
        modz.push_back(&Buttons::buttons[GUISettings::categoryIndex][i]);
    }

    if (GUISettings::categoryIndex != 0) {
        if (GUISettings::pageIndex > 0)
            modz.push_back(&backPage);
        if (GUISettings::pageIndex < maxPages)
            modz.push_back(&nextPage);
    }

    float threshold = 0.7f;
    bool up = stick.y >= threshold;
    bool down = stick.y <= -threshold;
    bool left = stick.x <= -threshold;
    bool right = stick.x >= threshold;

    CorrectIndexLOL(&modz);
    Button* cbutton = modz[GUISettings::cursorIndex];

    if (condition) {
        if (click && !cooldown) {
            if (cbutton->type == "toggle") {
                cbutton->enabled = !cbutton->enabled;
                if (cbutton->tooltip != "") //NotiLib::SendNotification("[<color=cyan>Kawaii</color>] " + cbutton->tooltip);

                if (cbutton->enabled && cbutton->enableMethod) {
                    cbutton->enableMethod();
                }
                if (!cbutton->enabled && cbutton->disableMethod) {
                    cbutton->disableMethod();
                }
            }
            else if (cbutton->type == "button") {
                if (cbutton->method) cbutton->method();
                if (cbutton->tooltip != "") //NotiLib::SendNotification("[<color=cyan>Kawaii</color>] " + cbutton->tooltip); 
            }
            cooldown = true;
        }

        if (time > cooldownTime) {
            if (up) {
                GUISettings::cursorIndex--;
                cooldownTime = time + .25f;
            } else if (down) {
                GUISettings::cursorIndex++;
                cooldownTime = time + .25f;
            } else if (right) {
                if (cbutton->type == "slider") {
                    cbutton->slide++;
                    cbutton->slide = std::clamp(cbutton->slide, 0, cbutton->maxSlide);
                }
                cooldownTime = time + .25f;
            } else if (left) {
                if (cbutton->type == "slider") {
                    cbutton->slide--;
                    cbutton->slide = std::clamp(cbutton->slide, 0, cbutton->maxSlide);
                }
                cooldownTime = time + .25f;
            }
        }
    }
    if (!click) {
        cooldown = false;
    }

    CorrectIndexLOL(&modz);

    Button* themeButton = FindButton("Menu Theme");

    Style* theme = &(Styles::allStyles[themeButton->slide]);

    if (theme->styleName == "rainbow") {
        vector<string> rnb = vector<string> { "red", "#FFA500", "yellow", "lime", "blue", "magenta" };

        Class Time = Class("UnityEngine", "Time");
        Property<float> time = Time.GetProperty("time");

        if (time() > rainbowCooldown) {
            rainbowCooldown = time() + .02f;
            rainbowIndex++;
            if (rainbowIndex > rnb.size() - 1) {
                rainbowIndex = 0;
            }

            theme = new Style {
                .styleName = "rainbow",
                .titleColor = rnb[rainbowIndex],
                .pointerColor = rnb[rainbowIndex],
                .enabledColor = rnb[rainbowIndex],
                .disabledColor = "red",
            };
        }
    }

    //This is the menu name
    std::string start = "<color=" + theme->titleColor + ">" + BNM_OBFUSCATE("-- KawaiiClique</color>"); //You can change this to your mod name.


    std::string menuText = start + "\n";


    for (int i = 0; i < modz.size(); ++i) {
        menuText += (GUISettings::cursorIndex == i ? "<color=" + theme->pointerColor + ">-></color> " : "") + "<color=" + theme->titleColor + ">" + modz[i]->getFullName() + "</color>";
        if (modz[i]->type == "toggle") {
            string ts = (modz[i]->enabled ? "<color=" + theme->enabledColor + ">= true</color>" : "<color=" + theme->disabledColor + ">= false</color>");
            menuText += " " + ts;
        }
        menuText += "\n";
    }

    gui->SetText(menuText);
}
