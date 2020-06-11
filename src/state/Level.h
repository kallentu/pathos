#ifndef PATHOS_LEVEL
#define PATHOS_LEVEL

#include <cstdio>
#include <vector>
#include <cmath>

namespace Pathos {

  // Experience levels and multipliers.
  class Level {
    size_t currentLevel;
    size_t currentExperience;

    // At vector position i, is the amount of experience needed to move to next level i + 1.
    std::vector<int> experienceThresholds;

  public:
    Level() : currentLevel{0}, currentExperience{0} {
      setUpLevels();
    }

    size_t getLevel() const { return currentLevel; }
    size_t getExperience() const { return currentExperience; }

    // Only able to modify experience by adding to it.
    void addExperience(size_t ex) {
      // Add to current experience, but need to check if player leveled up and adjust.
      currentExperience += ex;

      while (experienceThresholds.at(currentLevel) <= currentExperience) {
        currentLevel++;
        currentExperience -= experienceThresholds.at(currentLevel);
      }
    }

    // The amount of experience at the current level, needed to level up.
    size_t getExperienceThreshold() const { return experienceThresholds.at(currentLevel); }

  private:
    void setUpLevels() {
      int counter = 100;

      // Level 1 threshold, base case.
      experienceThresholds.push_back(counter);

      // Level 2 to 50 thresholds.
      for (int i = 1; i < 50; i++) {
        counter = std::pow(counter, 1.25);
        experienceThresholds.push_back(counter);
      }
    }
  };

} // namespace Pathos

#endif // PATHOS_LEVEL