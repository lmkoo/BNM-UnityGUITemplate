#pragma once
#include <iostream>
using namespace std;

#include "functional"

class Button {
public:
    string name;
    function<void()> method;
    function<void()> enableMethod;
    function<void()> disableMethod;

    bool enabled = false;

    string type = "toggle"; // toggle, button, slider

    int slide;
    int maxSlide = 4;

    vector<string> slideNames;
    string tooltip = "";

    std::string getFullName() {
        if (type != "slider") return name;
        string nn = name;
        if (slideNames.size() > 0) {
            nn += " (" + slideNames[slide] + ")";
        }

        nn += " [" + to_string(slide + 1) + "/" + to_string(maxSlide + 1) + "]";

        return nn;
    }
};