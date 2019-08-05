#ifndef PLAYAREA_H_
#define PLAYAREA_H_

#include "CardCollection.h"
#include "Deck.h"
#include "Constants.h"

namespace LIBCARD
{
class PlayArea : public CardCollection<PLAY_AREA_SIZE>
{
    public:
        PlayArea();
        ~PlayArea();
        void Add(Deck& _deck);

    private:
};
}


#endif // ifndef PLAYAREA_H_
