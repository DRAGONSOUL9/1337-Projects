from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard
from ex1.Deck import Deck


def draw_and_play(deck: Deck):
    """ draw a cart from a deck and play it"""
    try:
        card = deck.draw_card()
        print("\nDrew:", card.card_name_type())
        print("Play result:", card.play({}))
    except Exception as msg:
        print(msg)


print("\n=== DataDeck Deck Builder ===")
print("Building deck with different card types...")
deck = Deck()
deck.add_card(CreatureCard("Fire Dragon", 5, "Legendary", 7, 5))
deck.add_card(SpellCard("Lightning Bolt", 3, "Common", 'damage'))
deck.add_card(ArtifactCard("Mana Crysta", 2, "Common", 5,
                           "Permanent: +1 mana per turn"))
print("Deck stats:", deck.get_deck_stats())

print("Drawing and playing cards:")
draw_and_play(deck)
draw_and_play(deck)
draw_and_play(deck)

print("\nPolymorphism in action: Same interface, different card behaviors!")