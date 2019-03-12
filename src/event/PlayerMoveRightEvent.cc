#include "event/PlayerMoveRightEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "map/Ground.h"
#include "map/Map.h"

using namespace Pathos;

void PlayerMoveRightEvent::begin(PathosInstance *inst) {
  size_t y = inst->getPosition()->y;
  size_t x = inst->getPosition()->x;

  // Move right ONLY if the block to the right of the Player is Ground
  if (dynamic_cast<Ground *>(inst->getMap()->get(y, x + 1))) {
    inst->setPosition(y, x + 1);
  }
}
