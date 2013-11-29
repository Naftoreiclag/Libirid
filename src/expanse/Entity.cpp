/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Entity.h"

exp::Entity::Entity(Node* parent, EntityType entityType)
: entityType(entityType),
Node(NT_ENTITY, parent)
{

}

exp::Entity::~Entity()
{
    //dtor
}
