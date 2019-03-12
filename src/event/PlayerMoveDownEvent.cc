#include "event/PlayerMoveDownEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "map/Ground.h"
#include "map/Map.h"

using namespace Pathos;

void PlayerMoveDownEvent::begin(PathosInstance *inst) {
  size_t y = inst->getPosition()->y;
  size_t x = inst->getPosition()->x;

  // Move down ONLY if the block below Player is Ground
  if (dynamic_cast<Ground *>(inst->getMap()->get(y + 1, x))) {
    inst->setPosition(y + 1, x);
  }
}
