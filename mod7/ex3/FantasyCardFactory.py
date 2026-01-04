from ex0.Card import Card
from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex3.CardFactory import CardFactory

creatures: list = [
    {"name": "Fire Dragon", "cost": 5, "rarity":
     "Legendary", "attack": 7, "health": 5},
    {"name": "Goblin Warrior", "cost": 2, "rarity":
     "Common", "attack": 2, "health": 1},
    {"name": "Healing Angel", "cost": 4, "rarity":
     "Rare", "attack": 2, "health": 6},
    {"name": "Forest Sprite", "cost": 1, "rarity":
     "Common", "attack": 1, "health": 1}]
spells: list = [
    {"name": "Lightning Bolt", "cost": 3, "rarity":
     "Common", "effect_type": "damage"},
    {"name": "Healing Potion", "cost": 2, "rarity":
     "Common", "effect_type": "heal"},
    {"name": "Fireball", "cost": 4, "rarity":
     "Uncommon", "effect_type": "damage"}]
artifacts: list = [
    {"name": "Boots of Speed", "cost": 2, "rarity":
     "rare", "durability": 2, "effect": "Permanent: Cards cost 1 less mana"},
    {"name": "Cloak of Shadows", "cost": 3, "rarity":
     "rare", "durability": 3, "effect": "Permanent: Creatures have stealth"},
    {"name": "Staff of Elements", "cost": 6, "rarity":
     "Legendary", "durability": 7, "effect": "Permanent: +1 spell damage"}]


class FantasyCardFactory(CardFactory):

    def create_creature(self, name_or_power) -> Card:
        for card in creatures:
            card: Card
            if card['name'] == name_or_power:
                return (CreatureCard(card['name'], card['cost'],
                                     card['rarity'], card['attack'],
                                     card['health']))
        
        return CreatureCard()

    def create_spell(self, name_or_power) -> Card:
        pass

    def create_artifact(self, name_or_power) -> Card:
        pass

    def create_themed_deck(self, size: int) -> dict:
        pass

    def get_supported_types(self) -> dict:
        pass