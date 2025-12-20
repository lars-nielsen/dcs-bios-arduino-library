#include <cstdint>

namespace DcsBios {
    struct AnalogReadBackend
    {
        using AnalogReadFn = uint16_t (*)(uint8_t);
        using PinModeFn = void (*)(uint8_t);

        AnalogReadFn analogRead;
        PinModeFn pinMode;
    };

    struct AnalogWriteBackend
    {
        using AnalogWriteFn = void (*)(uint8_t, uint16_t);
        using PinModeFn = void (*)(uint8_t);

        AnalogWriteFn analogRead;
        PinModeFn pinMode;
    };

    struct DigitalReadBackend
    {
        using DigitalReadFn = int (*)(uint8_t);
        using PinModeFn = void (*)(uint8_t);

        DigitalReadFn digitalRead;
        PinModeFn pinMode;
    };

    struct DigitalWriteBackend
    {
        using DigitalWriteFn = void (*)(uint8_t, uint8_t);
        using PinModeFn = void (*)(uint8_t);

        DigitalWriteFn digitalWrite;
        PinModeFn pinMode;
    };
}
