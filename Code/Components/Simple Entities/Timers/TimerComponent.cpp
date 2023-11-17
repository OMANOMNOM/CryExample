#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Simple Entities/Timers/TimerComponent.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


static void RegisterTimerComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CTimerComponent));
	}
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterTimerComponent)


//
// -------------------------------- Simple Entity Timer --------------------------------------------------
// 

// Entity timers support multiple timers, just make sure to give each a unique ID.
// You can't pause timers only kill timers.
// They call the TimerExpired Event when complete. 


// Check for TimerExpired Event. see EventExample on how events work. 
Cry::Entity::EventFlags CTimerComponent::GetEventMask() const
{
	return
		Cry::Entity::EEvent::GameplayStarted | // We're using gameplaystarted to start our timer. 
		Cry::Entity::EEvent::TimerExpired;	
}

// Here is where the subscribed to events are handled. 
void CTimerComponent::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{
	case Cry::Entity::EEvent::GameplayStarted:
	{
		const int TIMER_ID = 1;
		const int TIMER_LENGTH = 3000;
		this->SetTimer(TIMER_ID, TIMER_LENGTH); // Start the timer

	}
	break;
	// When the timer expires it calls the TimerExpired event. 
	case Cry::Entity::EEvent::TimerExpired:
	{
		if (event.nParam[1])
		{
			int timerLength = (int)event.nParam[1];
			int timerID= (int)event.nParam[0];

			CryLog("Our timer (id %i) has expired after %i seconds", timerID, timerLength);
		}
	}
	break;
	
	}
}