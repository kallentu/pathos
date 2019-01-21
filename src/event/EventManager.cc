#include "event/EventManager.h"
#include "event/Event.h"
#include "event/PlayerAttackHostileEvent.h"
#include "map/Ground.h"
#include "map/Wall.h"
#include "mob/hostile/Hostile.h"
#include "mob/player/Player.h"
#include <memory>
#include <vector>

using namespace Pathos;

// TODO: Player own events.
std::vector<std::unique_ptr<Event>> EventManager::getEventList(Player &p) {

  // Player not used in defining events to return
  (void)p;

  std::vector<std::unique_ptr<Event>> events;
  return events;
}

std::vector<std::unique_ptr<Event>> EventManager::getEventList(Hostile &h) {

  // Hostile not used in defining events to return
  (void)h;

  std::vector<std::unique_ptr<Event>> events;
  events.push_back(std::make_unique<PlayerAttackHostileEvent>());
  return events;
}

std::vector<std::unique_ptr<Event>> EventManager::getEventList(Wall &w) {

  // Wall not used in defining events to return
  (void)w;

  std::vector<std::unique_ptr<Event>> events;
  return events;
}

// TODO: Walk to here event
std::vector<std::unique_ptr<Event>> EventManager::getEventList(Ground &g) {

  // Ground not used in defining events to return
  (void)g;

  std::vector<std::unique_ptr<Event>> events;
  return events;
}
