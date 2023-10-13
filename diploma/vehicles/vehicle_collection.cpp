#include "vehicle_collection.h"

VehicleCollection::VehicleCollection(int cap)
{
  this->capacity = cap;
  list = new Vehicle *[cap];

  for (int i = 0; i < size; ++i)
  {
    list[i] = nullptr;
  }
}

VehicleCollection::~VehicleCollection()
{
  for (int i = 0; i < capacity; ++i) {
    delete list[i];
  } 
}

bool VehicleCollection::add(Vehicle *veh_p)
{
  if (size < capacity) {
    list[size] = veh_p;
    ++size;
    return true;
  }
  return false;
}

int VehicleCollection::get_size()
{
  return size;
};