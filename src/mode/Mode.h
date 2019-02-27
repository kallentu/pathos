#ifndef PATHOS_MODE
#define PATHOS_MODE

namespace Pathos {

class ModeInputHandler;

// A mode that the game is currently in.
// Differentiates between different stages of the game.
// Eg. MovementMode, AttackMode, MerchantMode
class Mode {
public:
  Mode() {}
  virtual ~Mode() {}

  virtual ModeInputHandler *getHandler() const = 0;
};

} // namespace Pathos

#endif // PATHOS_MODE
