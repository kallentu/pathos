#ifndef PATHOS_MODE
#define PATHOS_MODE

#include "core/PathosInstance.h"

namespace Pathos {

class ModeHandler;

// A mode that the game is currently in.
// Differentiates between different stages of the game.
// Eg. MovementMode, AttackMode, MerchantMode
class Mode {
public:
  Mode(PathosInstance *inst) : inst{inst} {}
  virtual ~Mode() {}

  virtual ModeHandler *getHandler() const = 0;

protected:
  PathosInstance *inst;
};

} // namespace Pathos

#endif // PATHOS_MODE
