#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Blank Component/BlankComponent.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>

// ------------ Not sure you need these for a simple entity ------------
//#include <CrySchematyc/Reflection/TypeDesc.h>
//#include <CrySchematyc/Utils/EnumFlags.h>
//#include <CrySchematyc/Env/IEnvRegistry.h>
//#include <CrySchematyc/Env/Elements/EnvFunction.h>
//#include <CrySchematyc/Env/Elements/EnvSignal.h>
//#include <CrySchematyc/ResourceTypes.h>
//#include <CrySchematyc/MathTypes.h>
//#include <CrySchematyc/Utils/SharedString.h>

// Makes the component 'editable' within the CE editor. 
static void RegisterBlankComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CBlankComponent));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterBlankComponent)