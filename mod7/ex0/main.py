from ex0.CreatureCard import CreatureCard

print("\n=== DataDeck Card Foundation ===")

print("\nTesting Abstract Base Class Design:")

dragon = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)
print("\nCreatureCard Info:")
print(dragon.get_card_info())

print("\nPlaying Fire Dragon with 6 mana available:")
print("Playable:", dragon.is_playable(6))
goblin = CreatureCard("Goblin Warrior", 2, "common", 1, 3)
state: dict = {'card_played': 'Goblin Warrior', 'mana_used': 2,
               'effect': 'Creature summoned to battlefield'}
print("Play result:", dragon.play(state))

print("\nFire Dragon attacks Goblin Warrior:")
print("Attack result:", dragon.attack_target(goblin))

print('\nTesting insufficient mana (3 available):')
print("Playable:", dragon.is_playable(3))

print("\nAbstract pattern successfully demonstrated!")
