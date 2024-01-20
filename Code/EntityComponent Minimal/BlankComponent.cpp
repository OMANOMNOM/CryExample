#include "StdAfx.h" //Required in all classes to speed up compile
#include "BlankComponent.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


// Makes the component 'editable' within the CE editor. 
static void RegisterBlankComponentExample(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CBlankComponentExample));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterBlankComponentExample)