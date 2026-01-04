from ex0.Card import Card


class SpellCard(Card):
    """ class for spell cards"""

    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = None
        self.set_effect(effect_type)

    def play(self, game_state: dict) -> dict:
        game_state.update(
            {'card_played': self.name, 'mana_used': self.cost,
             'effect': f"Deal {self.cost} {self.effect_type} to target"})
        return game_state

    def resolve_effect(self, targets: list) -> dict:
        return {'effect': f"Deal {self.cost} {self.effect_type} to targets",
                'targets': targets}

    def set_effect(self, effect_type: str) -> None:
        lst: list = ['damage', 'heal', 'buff', 'debuff']
        try:
            if effect_type not in lst:
                raise ValueError("the effect is not valid")
        except ValueError as msg:
            print(msg)
        except Exception as msg:
            print(msg)

    def card_name_type(self):
        try:
            return f"{self.name} (Spell)"
        except AttributeError as msg:
            print(msg)
