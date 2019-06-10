#include "core/PathosInstance.h"
#include "mode/MovementMode.h"

int main() {
  Pathos::PathosInstance inst{};
  inst.runMode(std::make_unique<Pathos::MovementMode>(&inst));
  return 0;
}
