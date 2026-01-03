from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard
from ex0.Card import Card
import random


class Deck:
    def __init__(self):
        self.deck = {}

    def add_card(self, card: Card) -> None:
        self.deck[card.name] = card

    def remove_card(self, card_name: str) -> bool:
        self.deck.pop(card_name)

    def shuffle(self) -> None:
        pass

    def draw_card(self) -> Card:
        try:
            lst = list(self.deck.keys())
            card = self.deck.pop(random.choice(lst))
            return card
        except Exception as msg:
            print(msg)

    def get_deck_stats(self) -> dict:
        result: dict = {'total_cards': 0, 'creatures': 0, 'spells': 0,
                        'artifacts': 0, 'avg_cost': 0}
        cost_total = 0
        for card in self.deck.values():
            card: Card
            result['total_cards'] += 1
            if isinstance(card, CreatureCard):
                result['creatures'] += 1
            elif isinstance(card, SpellCard):
                result['spells'] += 1
            elif isinstance(card, ArtifactCard):
                result['artifacts'] += 1
            cost_total += card.cost
        if result['total_cards'] > 0:
            result['avg_cost'] = round(cost_total / result['total_cards'], 2)
        return result
