#ifndef PATHOS_STATS
#define PATHOS_STATS

namespace Pathos {

// Statistics within the game and about the player.
// Eg. how many kills of a mob, how many steps walked,
// who they've spoken to, triggers for quests.
class Stats final {
  static Stats *_instance;

  // See [KillWolvesQuest] and [Gaia].
  int wolvesKilled;

  // Private constructor for singleton pattern.
  Stats() : wolvesKilled{0} {}

public:
  static Stats *instance() {
    if (_instance == nullptr) _instance = new Stats();
    return _instance;
  }

  void setWolvesKilled(int newWolvesKilled) { wolvesKilled = newWolvesKilled; }
  void incrementWolvesKilled() { wolvesKilled++; }
  int getWolvesKilled() const { return wolvesKilled; }
};

} // namespace Pathos

#endif
