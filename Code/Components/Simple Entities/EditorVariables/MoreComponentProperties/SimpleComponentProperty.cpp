//#include "StdAfx.h" //Required in all classes to speed up compile
//#include "Components/Simple Entities/EditorVariables/SimpleComponentProperty.h"
//
//#include <CrySchematyc/Env/IEnvRegistrar.h>
//#include <CrySchematyc/Env/Elements/EnvComponent.h>
//#include <CryCore/StaticInstanceList.h>
//
//// Makes the component 'editable' within the CE editor. 
//static void RegisterSimpleComponentProperty(Schematyc::IEnvRegistrar& registrar)
//{
//	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
//	{
//		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSimpleComponentProperty));
//	}
//}
//
//CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterSimpleComponentProperty)
//
////
////	------------------------------ Event Stuff --------------------------------------------
////
//
//
//// Bit masks/enums are used to select which events the component is subscribed to. 
//// This funciton is called component creation, but you can change which events are subscribed later.
//// Look at EEvent to see what events are available
//
//Cry::Entity::EventFlags CSimpleComponentProperty::GetEventMask() const
//{
//	return
//		Cry::Entity::EEvent::BecomeLocalPlayer |
//		Cry::Entity::EEvent::Update |
//		Cry::Entity::EEvent::Reset;
//}
//
//// Here is where the subscribed to events are handled. 
//void CSimpleComponentProperty::ProcessEvent(const SEntityEvent& event)
//{
//	switch (event.event)
//	{
//	case Cry::Entity::EEvent::BecomeLocalPlayer:
//	{
//		// A good point to initilize the player
//	}
//	break;
//	case Cry::Entity::EEvent::Update: // Code here will be executed each frame
//	{
//		
//	}
//	break;
//	case Cry::Entity::EEvent::Reset:
//	{
//	}
//	break;
//	}
//}
