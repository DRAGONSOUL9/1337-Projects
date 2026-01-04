from ex0.Card import Card
from ex2.Combatable import Combatable
from ex2.Magical import Magical
from ex1.SpellCard import SpellCard


class EliteCard(Card, Combatable, Magical):
    def __init__(self, name: str, cost: int, rarity: str,
                 power: int, combat_type: str, mana: int):
        super().__init__(name, cost, rarity)
        self.power = power
        self.combat_type = combat_type
        self.mana = mana
        self.spells = []

    def play(self, game_state: dict) -> dict:
        game_state.update(
            {'card_played': self.name, 'mana_used': self.cost,
             'effect': 'EliteCard summoned to battlefield'})
        return game_state

    # combat abilitys
    def attack(self, target: Card) -> dict:
        return {'attacker': self.name, 'target': target.name,
                'damage': self.power, 'combat_type': self.combat_type}

    def defend(self, incoming_damage: int) -> dict:
        damage_taken: int = incoming_damage - self.cost
        is_alive: bool = True
        if self.cost < damage_taken:
            is_alive = False
        return {'defender': self.name, 'damage_taken': damage_taken,
                'damage_blocked': self.cost, 'still_alive': is_alive}

    def get_combat_stats(self) -> dict:
        return {'attack_power': self.power, 'defence': self.cost,
                'combat_type': self.combat_type}

    # magic abilitys
    def cast_spell(self, spell_name: str, targets: list) -> dict:
        card: Card = self.spells.pop()
        if card.cost > self.mana:
            return {'caster': self.name, 'spell': card.name,
                    'targets': targets, 'mana_used': 0}
        return {'caster': self.name, 'spell': card.name,
                'targets': targets, 'mana_used': card.cost}

    def add_spell(self, spell: SpellCard) -> None:
        if isinstance(spell, SpellCard) is False:
            print("the card given is not a spell card")
        self.spells.append(spell)

    def channel_mana(self, amount: int) -> dict:
        return {'channeled': amount,
                'total_mana': self.mana + amount}

    def get_magic_stats(self) -> dict:
        return {'mana_amount': self.mana,
                'spells': self.spells}
