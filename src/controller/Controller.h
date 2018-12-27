#ifndef PATHOS_CONTROLLER
#define PATHOS_CONTROLLER

#include <memory>

namespace Pathos {

class Input;

class Controller {
public:
  virtual ~Controller() {}
  virtual std::unique_ptr<Input> getInput() = 0;
};

} // namespace Pathos

#endif // PATHOS_CONTROLLER
