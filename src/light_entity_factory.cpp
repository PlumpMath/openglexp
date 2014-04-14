#include "light_entity_factory.h"
#include "entity_system/entity_pool.h"

#include "FLAT_utils.h"

void LightEntityFactory::produce(EntityPool* ep)
{
  Entity* e = ep->createEntity( component_signature_light_component | component_signature_spacial_component );  
  e->spacial_component->vel.x = 0;
  e->spacial_component->vel.y = 0;
  e->spacial_component->vel.z = 0;
  e->spacial_component->pos.x = 0;
  e->spacial_component->pos.y = 0;
  e->spacial_component->pos.z = 20;
}

