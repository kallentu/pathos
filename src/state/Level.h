#ifndef PATHOS_LEVEL
#define PATHOS_LEVEL

#include <cstdio>
#include <vector>
#include <cmath>

namespace Pathos {

  // Experience levels and multipliers.
  class Level {
    size_t currentExperience;

    // At vector position i, is the amount of experience needed to move to next level i + 1.
    std::vector<int> experienceThresholds;

  public:
    Level() : currentExperience{0} {
      setUpLevels();
    }

    size_t getLevel() const {
      for (int i = 0; i < 50; i++) {
        if (experienceThresholds.at(i) > currentExperience) return i;
      }
    }

    size_t getExperience() const { return currentExperience; }

    void setExperience(size_t ex) { currentExperience = ex; }

    // The amount of experience at the current level, needed to level up.
    size_t getExperienceThreshold() const { return experienceThresholds.at(getLevel()); }

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