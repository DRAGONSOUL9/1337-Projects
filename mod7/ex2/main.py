from ex2.EliteCard import EliteCard
from ex1.SpellCard import SpellCard

print("\n=== DataDeck Ability System ===")

print("EliteCard capabilities:",
      "- Card: ['play', 'get_card_info', 'is_playable']",
      "- Combatable: ['attack', 'defend', 'get_combat_stats']",
      "- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']", sep='\n')

card = EliteCard('Arcane Warrior', 3, "Mythical", 5, 'melee', 4)
card.add_spell(SpellCard("Lightning Bolt", 3, "Common", 'damage'))
card.add_spell(SpellCard("Fireball", 4, 'Uncommon', "damage"))
target = EliteCard('Goblin Assassin', 6, "common", 2, 'assassin', 0)

print(f"\nPlaying {card.name} ({type(card).__name__}):")

print("\nCombat phase:")
print("Attack result:", card.attack(target))
print("Defense result:", card.defend(5))

print("\nMagic phase:")
print("Spell cast:", card.cast_spell('Fireball', ['Enemy1', 'Enemy2']))
print("Mana channel:", card.channel_mana(3))

print("\nMultiple interface implementation successful!")
