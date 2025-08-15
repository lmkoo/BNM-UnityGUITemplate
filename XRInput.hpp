#pragma once

#include <BNM/Class.hpp>
#include <BNM/UnityStructures/Vector2.hpp>

using namespace std;
using namespace BNM;
using namespace BNM::Structures::Unity;

struct InputDevice {
    BNM::Types::ulong m_DeviceId;
    BNM::Types::ulong deviceId;
};

enum Controller {
    Left,
    Right
};

enum BoolFeature {
    PrimaryButton,
    PrimaryTouch,
    SecondaryButton,
    SecondaryTouch,
    GripButton,
    TriggerButton,
    MenuButton,
    Primary2DAxisClick,
    Primary2DAxisTouch,
    Secondary2DAxisClick,
    Secondary2DAxisTouch
};

enum FloatFeature {
    Trigger,
    Grip
};

enum Vector2Feature {
    Primary2DAxis,
    Secondary2DAxis
};

class XRInput {
private:
    static inline InputDevice leftController;
    static inline InputDevice rightController;

    static inline Class InputDevices;
    static inline bool init;


    static inline std::string BoolFeatureToString(BoolFeature feat);

    static inline std::string FloatFeatureToString(FloatFeature feat);

    static inline std::string Vector2FeatureToString(Vector2Feature feat);
public:
    static bool GetBoolFeature(BoolFeature feature, Controller con);

    static float GetFloatFeature(FloatFeature feature, Controller con);

    static Vector2 GetVector2Feature(Vector2Feature feature, Controller con);

    static void SendHapticImpulse(Controller con, float amp, float dur);
};