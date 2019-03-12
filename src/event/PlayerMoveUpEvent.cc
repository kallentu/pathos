#include "event/PlayerMoveUpEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "map/Ground.h"
#include "map/Map.h"

using namespace Pathos;

void PlayerMoveUpEvent::begin(PathosInstance *inst) {
  size_t y = inst->getPosition()->y;
  size_t x = inst->getPosition()->x;

  // Move up ONLY if the block above Player is Ground
  if (dynamic_cast<Ground *>(inst->getMap()->get(y - 1, x))) {
    inst->setPosition(y - 1, x);
  }
}
