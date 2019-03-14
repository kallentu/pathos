#ifndef PATHOS_QUEST
#define PATHOS_QUEST

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/quest/QuestRecipient.h"

namespace Pathos {

class Quest {
public:
  enum Status { NotStarted, InProgress, Completed, Failed };

  Quest(QuestGiver *questGiver)
      : status{NotStarted}, questGiver{questGiver}, questRecipient{nullptr} {}
  virtual ~Quest() {}

  void setStatus(Status s) { status = s; }
  Status getStatus() const { return status; }

  void setQuestGiver(QuestGiver *qg) { questGiver = qg; }
  QuestGiver *getQuestGiver() const { return questGiver; }

  void setQuestRecipient(QuestRecipient *qp) { questRecipient == qp; }
  QuestRecipient *getQuestRecipient() const { return questRecipient; }

private:
  Status status;

  // Will always report back to QuestGiver if completed/failed.
  QuestGiver *questGiver;

  // Nullable, doesn't need a recipient.
  QuestRecipient *questRecipient;
};

} // namespace Pathos

#endif // PATHOS_QUEST
