#include "request/QuestRequest.h"
#include "view/View.h"

using namespace Pathos;

void QuestRequest::beDrawnBy(View &view) const { view.draw(*this); }

Quest *QuestRequest::getQuest() const { return quest; }
