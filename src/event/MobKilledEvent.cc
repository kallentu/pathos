#include "event/MobKilledEvent.h"
#include "core/PathosInstance.h"
#include "mob/hostile/Hostile.h"
#include "map/Map.h"

using namespace Pathos;

void MobKilledEvent::begin(PathosInstance *inst) {
  // Assumed that actionable position is the killed mob at this point.
  Position *mob = inst->getActionablePosition();

  // Ensure that we are removing a hostile.
  if (dynamic_cast<Hostile *>(inst->getMap()->get(mob->y, mob->x)) != nullptr) {
    inst->getMap()->removeObjectFromPosition(mob->y, mob->x);
  }
}