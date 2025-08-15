#pragma once

#include <jni.h>
#include <BNM/Loading.hpp>
#include <BNM/UnityStructures.hpp>
#include <BNM/Method.hpp>
#include <BNM/Field.hpp>
#include <BNM/Property.hpp>
#include <BNM/FieldBase.hpp>
#include <BNM/MethodBase.hpp>
#include <BNM/PropertyBase.hpp>
#include <BNM/UserSettings/GlobalSettings.hpp>
#include <BNM/ClassesManagement.hpp>
#include <Internals.hpp>
#include <BNM/UserSettings/GlobalSettings.hpp>
#include <BNM/Class.hpp>
#include <BNM/Field.hpp>
#include <BNM/Method.hpp>
#include <BNM/Property.hpp>
#include <BNM/Operators.hpp>
#include <BNM/BasicMonoStructures.hpp>
#include <BNM/ComplexMonoStructures.hpp>
#include <BNM/ClassesManagement.hpp>
#include <algorithm>
#include <cmath>
#include <BNM/UnityStructures/Vector2.hpp>
#include <XRInput.hpp>


using namespace std;
using namespace BNM;
using namespace BNM::Structures;
using namespace BNM::Structures::Unity;
using namespace BNM::UnityEngine;
using namespace BNM::IL2CPP;

std::string XRInput::BoolFeatureToString(BoolFeature feat) {
    switch (feat) {
        case PrimaryButton: return "PrimaryButton";
        case PrimaryTouch: return "PrimaryTouch";
        case SecondaryButton: return "SecondaryButton";
        case SecondaryTouch: return "SecondaryTouch";
        case GripButton: return "GripButton";
        case TriggerButton: return "TriggerButton";
        case MenuButton: return "MenuButton";
        case Primary2DAxisClick: return "Primary2DAxisClick";
        case Primary2DAxisTouch: return "Primary2DAxisTouch";
        case Secondary2DAxisClick: return "Secondary2DAxisClick";
        case Secondary2DAxisTouch: return "Secondary2DAxisTouch";
        default: return "Unknown";
    }
}

std::string XRInput::FloatFeatureToString(FloatFeature feat) {
    switch (feat) {
        case Trigger: return "Trigger";
        case Grip: return "Grip";
        default: return "Unknown";
    }
}

std::string XRInput::Vector2FeatureToString(Vector2Feature feat) {
    switch (feat) {
        case Primary2DAxis: return "Primary2DAxis";
        case Secondary2DAxis: return "Secondary2DAxis";
        default: return "Unknown";
    }
}


bool XRInput::GetBoolFeature(BoolFeature feature, Controller con) {
    InputDevices = Class("UnityEngine.XR", "InputDevices");
    Method<InputDevice> GetDeviceAtXRNode = InputDevices.GetMethod("GetDeviceAtXRNode", 1);
    leftController = GetDeviceAtXRNode(4);
    rightController = GetDeviceAtXRNode(5);

    bool value;
    Method<bool> TryGetFeatureValue_bool_Method = InputDevices.GetMethod("TryGetFeatureValue_bool", 3);
    if (!TryGetFeatureValue_bool_Method.IsValid()) {
        auto TryGetFeatureValue_bool = (bool(*)(BNM::Types::ulong, Mono::String*, bool*))BNM::GetExternMethod("UnityEngine.XR.InputDevices::TryGetFeatureValue_float");
        if (!TryGetFeatureValue_bool((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(BoolFeatureToString(feature)), &value)) {
            return false;
        }
    } else {
        if (!TryGetFeatureValue_bool_Method((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(BoolFeatureToString(feature)), &value)) {
            return false;
        }
    }

    return value;
}

float XRInput::GetFloatFeature(FloatFeature feature, Controller con) {
    InputDevices = Class("UnityEngine.XR", "InputDevices");
    Method<InputDevice> GetDeviceAtXRNode = InputDevices.GetMethod("GetDeviceAtXRNode", 1);
    leftController = GetDeviceAtXRNode(4);
    rightController = GetDeviceAtXRNode(5);

    float value = .0f;
    Method<bool> TryGetFeatureValue_float_Method = InputDevices.GetMethod("TryGetFeatureValue_float", 3);
    if (!TryGetFeatureValue_float_Method.IsValid()) {
        auto TryGetFeatureValue_bool = (bool(*)(BNM::Types::ulong, Mono::String*, float*))BNM::GetExternMethod("UnityEngine.XR.InputDevices::TryGetFeatureValue_float");
        if (!TryGetFeatureValue_bool((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(FloatFeatureToString(feature)), &value)) {
            return .0f;
        }
    } else {
        if (!TryGetFeatureValue_float_Method((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(FloatFeatureToString(feature)), &value)) {
            return .0f;
        }
    }

    return value;
}

Vector2 XRInput::GetVector2Feature(Vector2Feature feature, Controller con) {
    InputDevices = Class("UnityEngine.XR", "InputDevices");
    Method<InputDevice> GetDeviceAtXRNode = InputDevices.GetMethod("GetDeviceAtXRNode", 1);
    leftController = GetDeviceAtXRNode(4);
    rightController = GetDeviceAtXRNode(5);

    Vector2 value = Vector2::zero;

    Method<bool> TryGetFeatureValue_Vector2f_Method = InputDevices.GetMethod("TryGetFeatureValue_Vector2f", 3);
    if (!TryGetFeatureValue_Vector2f_Method.IsValid()) {
        auto TryGetFeatureValue_bool = (bool(*)(BNM::Types::ulong, Mono::String*, Vector2*))BNM::GetExternMethod("UnityEngine.XR.InputDevices::TryGetFeatureValue_Vector2f");
        if (!TryGetFeatureValue_bool((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(Vector2FeatureToString(feature)), &value)) {
            return Vector2::zero;
        }
    } else {
        if (!TryGetFeatureValue_Vector2f_Method((con == Left ? leftController : rightController).m_DeviceId, CreateMonoString(Vector2FeatureToString(feature)), &value)) {
            return Vector2::zero;
        }
    }

    return value;
}

void XRInput::SendHapticImpulse(Controller con, float amp, float dur) {
    InputDevices = Class("UnityEngine.XR", "InputDevices");
    Method<InputDevice> GetDeviceAtXRNode = InputDevices.GetMethod("GetDeviceAtXRNode", 1);
    leftController = GetDeviceAtXRNode(4);
    rightController = GetDeviceAtXRNode(5);

    Method<void> SendHapticImpulse_Method = InputDevices.GetMethod("SendHapticImpulse", 4);
    if (!SendHapticImpulse_Method.IsValid()) {
        auto SendHapticImpulse = (void(*)(BNM::Types::ulong, uint, float, float))BNM::GetExternMethod("UnityEngine.XR.InputDevices::SendHapticImpulse");
        SendHapticImpulse((con == Left ? leftController : rightController).m_DeviceId, 0u, amp, dur);
        return;
    }
    SendHapticImpulse_Method((con == Left ? leftController : rightController).m_DeviceId, 0u, amp, dur);
}