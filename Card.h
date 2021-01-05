#ifndef CARD_H_
#define CARD_H_

class Card
{
public:
  Card(const std::string &, const std::string &);
  Card(); //SECOND INSTRUCTOR TO CREATE AN ARRAY
  std::string print();
  std::string getFace();
  std::string getSuit();
  int cardValue();
  int cardValueBJ();

private:
  std::string face;
  std::string suit;
};

#endif /* CARD_H_ */
