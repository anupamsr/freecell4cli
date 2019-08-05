#ifndef CARD_H_
#define CARD_H_

namespace LIBCARD
{
enum class CardSuit {
    NOTHING, JOCKER, CLUBS, HEARTS, SPADES, DIAMONDS
};

enum class CardRank {
    NOTHING, JOCKER, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

class Card
{
    public:
        explicit Card(const CardSuit& _suit,
                      const CardRank& _rank);
        ~Card();
        CardSuit GetSuit() const;
        CardRank GetRank() const;
        void     SetSuit(const CardSuit& _suit);
        void     SetRank(const CardRank& _rank);

    private:
        CardSuit m_suit;
        CardRank m_rank;
};
}

#endif // ifndef CARD_H_
