#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Simple Entities/CVAR/ConsoleVariable.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>
#include <CrySystem/ConsoleRegistration.h>

// Makes the component 'editable' within the CE editor. 
static void RegisterConsoleVaraible(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CConsoleVaraible));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterConsoleVaraible)

CConsoleVaraible::~CConsoleVaraible()
{
	gEnv->pConsole->UnregisterVariable("specialNumber"); // REMEMBER TO REMOVE VARAIBLE IN DESTRUCTOR!!!!!!!
}

CConsoleVaraible::CConsoleVaraible()	:
	specialNumber(42)
{
	REGISTER_CVAR2("specialNumber", &specialNumber, specialNumber, VF_NULL, "This is a number we can change with console varaibles");
}
