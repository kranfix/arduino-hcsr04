#include <stdint.h>

class HCSR04 {
  uint8_t trigger;
  uint8_t echo;
  float vel; // sound speed

public:
  HCSR04(uint8_t trigger, uint8_t echo, float vel); //343e-4 * 1.2
  float loop();
};
