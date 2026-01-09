from enum import Enum
from datetime import datetime
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(Enum):
    CADET = 'cadet'
    OFFICER = 'officer'
    LIEUTENANT = 'lieutenant'
    CAPTAIN = 'captain'
    COMMANDER = 'commander'


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True

    def member_info(self):
        return f"- {self.name} ({self.rank.value}) - {self.specialization}"


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = 'planned'
    budget_millions: float = Field(..., ge=1, le=10000)

    @model_validator(mode='after')
    def mession_validation(self):
        if self.mission_id.startswith('M') is False:
            raise ValueError("Mission ID must start with \"M\"")
        rank_lst: list[Rank] = [person.rank for person in self.crew]
        if Rank.CAPTAIN not in rank_lst and Rank.COMMANDER not in rank_lst:
            raise ValueError("Mission must have at least "
                             "one Commander or Captain")
        for person in self.crew:
            if person.is_active is False:
                raise ValueError("All crew members must be active")
        if self.duration_days > 365:
            size: int = len(self.crew)
            experts: list = [person for person in self.crew
                             if person.years_experience > 5]
            if len(experts) < (size / 2):
                raise ValueError("Long missions (> 365 days) need 50% "
                                 "experienced crew (5+ years)")
        return self

    def get_info(self):
        print(f"Mission: {self.mission_name}",
              f"ID: {self.mission_id}",
              f"Destination: {self.destination}",
              f"Duration: {self.duration_days} days",
              f"Budget: ${self.budget_millions}M",
              f"Crew size: {len(self.crew)}",
              "Crew members:", sep='\n')
        for person in self.crew:
            print(person.member_info())


def create_member(person: dict) -> CrewMember:
    """ this function is not meant to be used alone """
    try:
        person = CrewMember(
            member_id=person['member_id'],
            name=person['name'],
            rank=person['rank'],
            age=person['age'],
            specialization=person['specialization'],
            years_experience=person['years_experience'],
            is_active=person['is_active'])
        return person
    except Exception as msg:
        return f"This key ({msg}) is Wrong double check"


def create_mission(entry: dict) -> SpaceMission:

    try:
        mission = SpaceMission(
            mission_id=entry['mission_id'],
            mission_name=entry['mission_name'],
            destination=entry['destination'],
            launch_date=entry['launch_date'],
            duration_days=entry['duration_days'],
            crew=[create_member(person) for person in entry['crew']],
            mission_status=entry['mission_status'],
            budget_millions=entry['budget_millions'])

        print("Valid mission created:")
        mission.get_info()
        return mission
    except ValidationError as msg:
        try:
            lst: list = msg.errors()
            msg: str = lst[0]['msg']
            lst: list = msg.split(',')
            msg = lst.pop()
            msg = msg.lstrip(' ')
            print("Expected validation error:",
                  f"{msg}", sep='\n')
        except Exception:
            lst: list = msg.errors()
            print("Expected validation error:",
                  lst[0]['msg'], sep='\n')
        return None
    except KeyError as msg:
        print(f"This key ({msg}) is Wrong double check")


def main():
    data = [
        {
            'mission_id': 'M2024_MARS',
            'mission_name': 'Mars Colony Establishment',
            'destination': 'Mars',
            'launch_date': '2024-03-30T00:00:00',
            'duration_days': 900,
            'crew': [
                {
                    'member_id': 'CM001',
                    'name': 'Sarah Connor',
                    'rank': 'commander',
                    'age': 43,
                    'specialization': 'Mission Command',
                    'years_experience': 19,
                    'is_active': True
                },
                {
                    'member_id': 'CM002',
                    'name': 'John Smith',
                    'rank': 'lieutenant',
                    'age': 43,
                    'specialization': 'Navigation',
                    'years_experience': 30,
                    'is_active': True
                },
                {
                    'member_id': 'CM003',
                    'name': 'Alice Johnson',
                    'rank': 'officer',
                    'age': 35,
                    'specialization': 'Engineering',
                    'years_experience': 15,
                    'is_active': True
                }
            ],
            'mission_status': 'planned',
            'budget_millions': 2500.0},

        {
            'mission_id': 'M2024_TITAN',
            'mission_name': 'Solar Observatory Research Mission',
            'destination': 'Solar Observatory',
            'launch_date': '2024-03-30T00:00:00',
            'duration_days': 451,
            'crew': [
                {
                    'member_id': 'CM001',
                    'name': 'Sarah Williams',
                    'rank': 'cadet',
                    'age': 43,
                    'specialization': 'Mission Command',
                    'years_experience': 19,
                    'is_active': True
                },
                {
                    'member_id': 'CM002',
                    'name': 'James Hernandez',
                    'rank': 'lieutenant',
                    'age': 43,
                    'specialization': 'Pilot',
                    'years_experience': 30,
                    'is_active': True
                },
                {
                    'member_id': 'CM003',
                    'name': 'Anna Jones',
                    'rank': 'officer',
                    'age': 35,
                    'specialization': 'Communications',
                    'years_experience': 15,
                    'is_active': False
                }
            ],
            'mission_status': 'planned',
            'budget_millions': 2208.1}]

    print("Space Mission Crew Validation")
    print("=========================================")
    create_mission(data[0])

    print("\n=========================================")
    create_mission(data[1])


main()
