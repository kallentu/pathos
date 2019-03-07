#include "event/QuitEvent.h"
#include "core/PathosInstance.h"

using namespace Pathos;

void QuitEvent::begin(PathosInstance *inst) { inst->stop(); }
