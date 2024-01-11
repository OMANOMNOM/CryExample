#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Simple Entities/PhysicsComponent/CollisionComponent.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


// Makes the component 'editable' within the CE editor. 
static void RegisterCollisionComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CCollisionComponent));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterCollisionComponent)

void CCollisionComponent::Initialize()
{
	// 1. Create rigid body component
	m_pRigidbodyComponent = m_pEntity->GetOrCreateComponent<Cry::DefaultComponents::CRigidBodyComponent>();

	// 2. Load the sphere geometry 
	int slot = m_pEntity->LoadGeometry(GetOrMakeEntitySlotId(), "%ENGINE%/EngineAssets/Objects/primitive_sphere.cgf");
	if (slot != -1)
	{
		IMaterial* pMaterial = gEnv->p3DEngine->GetMaterialManager()->LoadMaterial("%ENGINE%/EngineAssets/TextureMsg/DefaultSolids");
		if (pMaterial != nullptr)
		{
			m_pEntity->SetMaterial(pMaterial);
		}
	}

	// 3. Physicalize the geometry. (Make it available to the physics system by setting its physics settings)
	SEntityPhysicalizeParams physParams;
	physParams.type = PE_RIGID;
	physParams.mass = 90.f;
	m_pEntity->Physicalize(physParams);

}


Cry::Entity::EventFlags CCollisionComponent::GetEventMask() const
{
	return
		Cry::Entity::EEvent::BecomeLocalPlayer |
		Cry::Entity::EEvent::Update |
		Cry::Entity::EEvent::Reset;
}

// Here is where the subscribed to events are handled. 
void CCollisionComponent::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::PhysicsCollision:
	{
		CryLog("A Collision Took place!!!!");
		// Get the EventPhysCollision structure describing the collision that occurred
		const EventPhysCollision* pPhysCollision = reinterpret_cast<const EventPhysCollision*>(event.nParam[0]);

		// The EventPhysCollision provides information for both the source and target entities
		// Therefore, we store the indices of this entity (and the other collider)
		// This can for example be used to get the surface identifier (and thus the material) of the part of our entity that collided
		const int thisEntityIndex = static_cast<int>(event.nParam[1]);
		// Calculate the index of the other entity
		const int otherEntityIndex = (thisEntityIndex + 1) % 2;

		// Gets use the PhysicalEntity Of The Other Collider, note this is independant of entites (Ientity), but they can be attached via the entity system
		IPhysicalEntity* otherPhysEntity = pPhysCollision->pEntity[otherEntityIndex];
		gEnv->pEntitySystem->GetEntityFromPhysics(otherPhysEntity);

		//virtual IEntity* GetEntityFromPhysics(IPhysicalEntity * pPhysEntity) const = 0;

		
		// -----------  Other cool stuff we can do. ---------------------- 

		/*
		//Get the contact point (in world coordinates) of the two entities
		const Vec3& contactPoint = pPhysCollision->pt;


		if (!contactPoint.IsZero())
		{
		}

		// Get the collision normal vector
		const Vec3& contactNormal = pPhysCollision->n;

		if (!contactNormal.IsZero())
		{
		}

		// Get properties for our entity, starting with the local velocity of our entity at the contact point
		const Vec3& relativeContactVelocity = pPhysCollision->vloc[thisEntityIndex];

		if (!relativeContactVelocity.IsZero())
		{
		}

		// Get the mass of our entity
		const float contactMass = pPhysCollision->mass[thisEntityIndex];

		if (contactMass > 0.0f)
		{
		}

		// Get the identifier of the part of our entity that collided
		// This is the same identifier that is added with IPhysicalEntity::AddGeometry
		const int contactPartId = pPhysCollision->partid[thisEntityIndex];

		if (contactPartId)
		{
			// Do something here!
		}

		// Get the surface on our entity that collided
		const int contactSurfaceId = pPhysCollision->idmat[thisEntityIndex];
		// Get the ISurfaceType representation of the surface that collided
		if (const ISurfaceType* pContactSurface = gEnv->p3DEngine->GetMaterialManager()->GetSurfaceType(contactSurfaceId))
		{
			//Interact with pContactSurface here
		} */
	}
	break;
	
	}
}