#include "event/EventManager.h"
#include "event/Event.h"
#include "event/PlayerAttackHostileEvent.h"
#include "event/PlayerTalkToFriendlyEvent.h"
#include "map/Ground.h"
#include "map/Wall.h"
#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Merchant.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
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

// TODO: Friendly talk events
std::vector<std::unique_ptr<Event>> EventManager::getEventList(Friendly &f) {

  // Friendly not used in defining events to return
  (void)f;

  std::vector<std::unique_ptr<Event>> events;
  events.push_back(std::make_unique<PlayerTalkToFriendlyEvent>(&f));
  return events;
}

// TODO: Romance events
std::vector<std::unique_ptr<Event>> EventManager::getEventList(Romanceable &r) {

  // Romanceable not used in defining events to return
  (void)r;

  std::vector<std::unique_ptr<Event>> events;
  events.push_back(std::make_unique<PlayerTalkToFriendlyEvent>(&r));
  return events;
}

// TODO: QuestGiver events
std::vector<std::unique_ptr<Event>> EventManager::getEventList(QuestGiver &qg) {

  // QuestGiver not used in defining events to return
  (void)qg;

  std::vector<std::unique_ptr<Event>> events;
  return events;
}

// TODO: Merchant events
std::vector<std::unique_ptr<Event>> EventManager::getEventList(Merchant &m) {

  // Merchant not used in defining events to return
  (void)m;

  std::vector<std::unique_ptr<Event>> events;
  events.push_back(std::make_unique<PlayerTalkToFriendlyEvent>(&m));
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
