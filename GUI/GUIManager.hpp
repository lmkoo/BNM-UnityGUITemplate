#pragma once

// Made by pubertcs, please credit me when using, or atleast mention my name
// discord.gg/spm is cool 😎

#include <BNMResolve.hpp>

using namespace BNM;
using namespace BNM::Structures;
using namespace BNM::Structures::Unity;
using namespace BNM::IL2CPP;

#define O(str) BNM_OBFUSCATE(str)

struct GUIManager {
private:
    bool _initialized;
    GameObject* menuInstance;
    Text* menuText;

public:
    GUIManager() : _initialized(false), menuInstance(nullptr), menuText(nullptr) {
        BNM_LOG_INFO("SPM | Created new GUIManager");
    }

    void Init(Transform* cameraTransform, TextAnchor dockPos, Font* customFont) {
        BNM_LOG_INFO("SPM | GUIManager::Init Called");
        if (_initialized) return;
        _initialized = true;

        menuInstance = (GameObject*)GameObject::GetClass().CreateNewObjectParameters(CreateMonoString(O("[Menu Instance]")));

        Canvas* canvas = (Canvas*)menuInstance->AddComponent(Canvas::GetType());
        canvas->SetRenderMode(RenderMode::WorldSpace);

        RectTransform* menuTransform = (RectTransform*)menuInstance->GetComponent(RectTransform::GetType());

        Font* fontToUse = customFont;
        if (customFont == nullptr || !customFont->Alive()) {
            fontToUse = (Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf");
        }

        menuText = (Text*)menuInstance->AddComponent(Text::GetType());

        Material* guiMaterial = (Material*)Material::GetClass().CreateNewObjectParameters(Shader::Find(
                "GUI/Text Shader"));


        menuTransform->SetParent(cameraTransform, false);
        menuText->SetFont(fontToUse);
        menuTransform->SetLocalEulerAngles(Vector3::zero);
        menuTransform->SetSizeDelta(Vector2(300.0f, 250.0f));
        menuTransform->SetLocalPosition(Vector3(-0.1f, -0.3297f, 1.6f));
        menuTransform->SetLocalScale(Vector3(0.005f, 0.005f, 0.005f));

        menuText->SetMaterial(guiMaterial);

        CanvasScaler* canvasScaler = (CanvasScaler*)menuInstance->AddComponent(CanvasScaler::GetType());

        canvasScaler->SetDynamicPixelsPerUnit(65.f);
        menuText->SetFontStyle(FontStyle::Bold);
        SetDock(dockPos);
    }
    void Destroy() {
        if (!_initialized) return;
        _initialized = false;

        if (menuInstance) {
            GameObject::Destroy(menuInstance);
            menuInstance = nullptr;
        }
    }

    void SetText(const std::string& tex) {
        menuText->SetText(tex);
    }

    void SetDock(TextAnchor dockPos) {
        menuText->SetAlignment((TextAnchor)dockPos);
    }
};
