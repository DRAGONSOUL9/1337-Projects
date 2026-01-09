from enum import Enum
from pydantic import BaseModel, model_validator, Field, ValidationError
from typing import Optional
from datetime import datetime


class ContactType(Enum):
    RADIO = 'radio'
    VISUAL = 'visual'
    PHYSICAL = 'physical'
    TELEPATHIC = 'telepathic'


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: Optional[str] = Field(None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def validate_id(self):
        if self.contact_id.startswith('AC') is False:
            raise ValueError(f"ID: ({self.contact_id}) does not "
                             "start with (AC)")
        if self.message_received and self.is_verified is False:
            raise ValueError("the message recieved is not verified")
        if self.witness_count < 3:
            raise ValueError(f"{self.contact_type.value.capitalize()} contact"
                             " requires at least 3 witnesses")
        if self.signal_strength <= 7:
            raise ValueError("The Signal was weak")
        return self

    def get_info(self):
        print(f"ID: {self.contact_id}",
              f"Type: {self.contact_type.value}",
              f"Location: {self.location}",
              f"Signal: {self.signal_strength}/10",
              f"Duration: {self.duration_minutes} minutes",
              f"Witnesses: {self.witness_count}",
              f"Message: {self.message_received}", sep='\n')


def create_station(entry: dict) -> AlienContact:
    try:
        station = AlienContact(
            contact_id=entry['contact_id'],
            timestamp=entry['timestamp'],
            location=entry['location'],
            contact_type=entry['contact_type'],
            signal_strength=entry['signal_strength'],
            duration_minutes=entry['duration_minutes'],
            witness_count=entry['witness_count'],
            message_received=entry['message_received'],
            is_verified=entry['is_verified'])
        print("Valid station created:")
        station.get_info()
        return station
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


def main():
    data = [
        {
            'contact_id': 'AC_2024_001',
            'timestamp': '2024-01-20T00:00:00',
            'location': 'Area 51, Nevada',
            'contact_type': 'radio',
            'signal_strength': 8.5,
            'duration_minutes': 45,
            'witness_count': 5,
            'message_received': 'Greetings from Zeta Reticuli',
            'is_verified': True},
        {
            'contact_id': 'AC_2024_002',
            'timestamp': '2024-08-20T00:00:00',
            'location': 'Mauna Kea Observatory, Hawaii',
            'contact_type': 'telepathic',
            'signal_strength': 9.6,
            'duration_minutes': 65,
            'witness_count': 2,
            'message_received': 'This is a test',
            'is_verified': True}]

    print("Alien Contact Log Validation")
    print("========================================")
    create_station(data[0])

    print("\n========================================")
    create_station(data[1])


main()
