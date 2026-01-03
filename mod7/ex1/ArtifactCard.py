from ex0.Card import Card


class ArtifactCard(Card):
    def __init__(self, name: str, cost: int, rarity: str,
                 durability: int, effect: str):
        super().__init__(name, cost, rarity)
        self.durability = durability
        self.effect = effect

    def play(self, game_state: dict) -> dict:
        game_state.update(
            {'card_played': self.name, 'mana_used': self.cost,
             'effect': self.effect})
        return game_state

    def activate_ability(self) -> dict:
        pass

    def card_name_type(self):
        try:
            return f"{self.name} (Artifact)"
        except AttributeError as msg:
            print(msg)
