#include "StdAfx.h" //Required in all classes to speed up compile
#include "EntityComponent basics/Input Examples/InputEntity.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>

static void RegisterInputComponentExample(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CInputEntityExample));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterInputComponentExample)

void CInputEntityExample::Initialize()
{
	// Create the Input component
	m_pInputComponent = m_pEntity->GetOrCreateComponent<Cry::DefaultComponents::CInputComponent>();



	// Register an action, and the callback that will be sent when it's m_pEntity
	// If you're unsure of the syntax below, look up lamda expressions. 
	m_pInputComponent->RegisterAction("player", "moveleft", [this](int activationMode, float value) 
		{ 
			CryLog("a key has been pressed and its value is %f", value);  
		});
	// Bind the 'A' key the "moveleft" action defined above.
	m_pInputComponent->BindAction("player", "moveleft", eAID_KeyboardMouse, EKeyId::eKI_F);

}
