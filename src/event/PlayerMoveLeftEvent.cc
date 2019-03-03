#include "event/PlayerMoveLeftEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "map/Ground.h"
#include "map/Map.h"

using namespace Pathos;

void PlayerMoveLeftEvent::begin(PathosInstance *inst) {
  size_t y = inst->getPosition()->y;
  size_t x = inst->getPosition()->x;

  // Move left ONLY if the block to the left of Player is Ground
  if (dynamic_cast<Ground *>(inst->getMap()->get(y, x))) {
    inst->setPosition(y, x - 1);
  }
}
