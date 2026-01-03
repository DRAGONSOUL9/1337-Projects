from abc import ABC, abstractmethod


class Card(ABC):
    """ this is the base class for any card type"""
    def __init__(self, name: str, cost: int, rarity: str) -> None:
        """ the constructor for any card"""
        self.name = name
        self.cost = cost
        self.rarity = rarity

    @abstractmethod
    def play(self, game_state: dict) -> dict:
        ...

    def get_card_info(self) -> dict:
        return {'name': self.name, 'cost': self.cost, 'rarity': self.rarity}

    def is_playable(self, available_mana: int) -> bool:
        if available_mana >= self.cost:
            return True
        return False

    def card_name_type(self):
        try:
            return f"{self.name} (Card)"
        except AttributeError as msg:
            print(msg)
