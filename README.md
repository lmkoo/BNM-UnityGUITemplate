# RemakeOfSPMGui
Old leaked SPM Gui remade by Ossuary, Mr.E, and JaeAPK. [Credits](https://kawaiiclique.vercel.app/Project/CPPMenuHook)

# How to add files
Put all of these files in your Include folder and add ModGUI.cpp & GUISettings.cpp to your CMakeLists. 

# Usage for hooks
```cpp
#include <GUIInclude.hpp>
void new_Awake(void* instance) {
    ModGUI::Init();
}

void new_LateUpdate(void* instance) {
    ModGUI::Update();
}
```

# Dependencies

- [BNMResolve](https://github.com/Livku2/BNMResolve)
- [BNM-Android](https://github.com/ByNameModding/BNM-Android)

# Help
If you need help with coding or this GUI Temp.

Join My Discord - [Discord Link](https://discord.gg/Jn2tBbNNfj)
--

This code is allowed to be used by anyone, just credit the people in the credits.
