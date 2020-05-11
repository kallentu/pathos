#include "request/CombatRequest.h"
#include "mob/player/Player.h"
#include "view/View.h"

using namespace Pathos;

void CombatRequest::beDrawnBy(View &view) const { view.draw(*this); }

