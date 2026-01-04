from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard
from ex0.Card import Card
import random


class Deck:
    def __init__(self):
        self.deck = []

    def add_card(self, card: Card) -> None:
        if isinstance(card, Card):
            self.deck.append(card)
        print("ERROR: The card given to be added is not a valid card")

    def remove_card(self, card_name: str) -> bool:
        for card in self.deck:
            card: Card
            if card.name == card_name:
                self.deck.pop(card)
                return True
        return False

    def shuffle(self) -> None:
        """ this is used to shuffle the deck of cards"""
        random.shuffle(self.deck)

    def draw_card(self) -> Card:
        try:
            card = self.deck.pop(0)
            return card
        except IndexError:
            print("ERROR: the deck is empty")

    def get_deck_stats(self) -> dict:
        result: dict = {'total_cards': 0, 'creatures': 0, 'spells': 0,
                        'artifacts': 0, 'avg_cost': 0}
        cost_total = 0
        for card in self.deck:
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
