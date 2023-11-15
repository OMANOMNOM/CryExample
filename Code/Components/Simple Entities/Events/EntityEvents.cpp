#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Simple Entities/Events/EntityEvents.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>

// Makes the component 'editable' within the CE editor. 
static void RegisterEntityEventsComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CEntityEventsComponent));
	}
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterEntityEventsComponent)

//
//	------------------------------ Event Stuff --------------------------------------------
//


// Bit masks/enums are used to select which events the component is subscribed to. 
// This funciton is called component creation, but you can change which events are subscribed later.
// Look at EEvent to see what events are available

Cry::Entity::EventFlags CEntityEventsComponent::GetEventMask() const
{
	return
		Cry::Entity::EEvent::BecomeLocalPlayer |
		Cry::Entity::EEvent::Update |
		Cry::Entity::EEvent::Reset;
}

// Here is where the subscribed to events are handled. 
void CEntityEventsComponent::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::BecomeLocalPlayer:
	{
		// A good point to initilize the player
	}
	break;
	case Cry::Entity::EEvent::Update: // Code here will be executed each frame
	{
		// Some event.event 's provide additional parameters
		const float frameTime = event.fParam[0];

		CryLog("Frame time is: %f", frameTime); // Prints frametime every frame to the log. (just an example use of update event)
	}
	break;
	case Cry::Entity::EEvent::Reset:
	{
		// Disable the player when leaving the game mode
	}
	break;
	}
}