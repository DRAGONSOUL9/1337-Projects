from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(None, max_length=200)

    def get_info(self):
        if self.is_operational:
            status = 'Operational'
        else:
            status = 'Maintenance'
        print(f"ID: {self.station_id}",
              f"Name: {self.name}",
              f"Crew: {self.crew_size} people",
              f"Power: {self.power_level}%",
              f"Oxygen: {self.oxygen_level}%",
              f"Status: {status}", sep='\n')


def create_station(station_data: dict) -> SpaceStation:
    try:
        station = SpaceStation(
            station_id=station_data['station_id'],
            name=station_data['name'],
            crew_size=station_data['crew_size'],
            power_level=station_data['power_level'],
            oxygen_level=station_data['oxygen_level'],
            last_maintenance=station_data['last_maintenance'],
            is_operational=station_data['is_operational'],
            notes=station_data['notes'])
        print("Valid station created:")
        station.get_info()
        return station
    except ValidationError as msg:
        lst: list = msg.errors()
        print("Expected validation error:",
              lst[0]['msg'], sep='\n')
        return None
    except KeyError as msg:
        print(f"This key ({msg}) is Wrong double check")


def main():
    data = [
        {
            'station_id': 'ISS001',
            'name': 'International Space Station',
            'crew_size': 6,
            'power_level': 85.5,
            'oxygen_level': 92.3,
            'last_maintenance': '2023-07-11T00:00:00',
            'is_operational': True,
            'notes': None
        },
        {
            'station_id': 'LGW723',
            'name': 'Mars Orbital Platform',
            'crew_size': 21,
            'power_level': 90.8,
            'oxygen_level': 87.3,
            'last_maintenance': '2023-09-25T00:00:00',
            'is_operational': False,
            'notes': 'System diagnostics required'
        }]
    print("Space Station Data Validation")
    print("========================================")
    create_station(data[0])

    print("\n========================================")
    create_station(data[1])


main()
