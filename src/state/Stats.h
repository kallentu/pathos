#ifndef PATHOS_STATS
#define PATHOS_STATS

namespace Pathos {

// Statistics within the game and about the player.
// Eg. how many kills of a mob, how many steps walked,
// who they've spoken to, triggers for quests.
struct Stats final {
  // See [KillWolvesQuest] and [Gaia].
  int wolvesKilled;

  Stats() : wolvesKilled{0} {}
};

} // namespace Pathos

#endif
