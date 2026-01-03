from ex0.Card import Card


class CreatureCard(Card):
    """ this class is for creature cards"""
    def __init__(self, name: str, cost: int, rarity: str,
                 attack: int, health: int) -> None:
        super().__init__(name, cost, rarity)
        self.__attack = 0
        self.__health = 0
        self.set_attributes(attack, health)

    def play(self, game_state: dict) -> dict:
        """
        Change the state of the game

        Args:
            game_state: the current state of the game

        Returns:
            Dictionary with the new state
        """
        game_state.update({'card_played': self.name, 'mana_used': self.cost,
                           'effect': 'Creature summoned to battlefield'})
        return game_state

    def get_card_info(self) -> dict:
        """
        Returns:
            Dictionary containing the data of the card
        """
        attr: dict = super().get_card_info()
        attr.update({'type': 'Creature', 'attack': self.__attack,
                     'health': self.__health})
        return attr

    def attack_target(self, target: Card):
        """
        This is how a creature attacks its target
        Args:
            the target that will be attacked
        Returns:
            Dictionary of what happened
        """
        return {'attacker': self.name, 'target': target.name,
                'damage_dealt': self.__attack, 'combat_resolved': True}

    def set_attributes(self, attack: int, health: int) -> None:
        """ validate and set the attack attribute"""
        try:
            if attack < 0:
                raise ValueError(f"attack value is negative -> {attack}")
            if health < 0:
                raise ValueError(f"health value is negative -> {attack}")
            self.__attack = attack
            self.__health = health
        except ValueError as msg:
            print(msg)
        except Exception as msg:
            print(msg)

    def card_name_type(self):
        try:
            return f"{self.name} (Creature)"
        except AttributeError as msg:
            print(msg)
