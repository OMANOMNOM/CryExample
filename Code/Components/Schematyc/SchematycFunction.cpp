#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Schematyc/SchematycFunction.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


//
// 
// 

#include <CrySchematyc/Env/Elements/EnvFunction.h>

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
static void RegisterSchematycFunction(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSchematycFunction));

		{
			auto const pFunction = SCHEMATYC_MAKE_ENV_FUNCTION(&CSchematycFunction::SetEnabled, "{2D222625-98F1-4605-ADE1-800245C6D924}"_cry_guid, "Set Enabled");
			pFunction->SetDescription("Controls whether the spawner is enabled during runtime.");
			pFunction->SetFlags({ Schematyc::EEnvFunctionFlags::Member });
			pFunction->BindInput(1, 'enab', "Enabled");
			componentScope.Register(pFunction);
		}
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterSchematycFunction)

void CSchematycFunction::SetEnabled(const bool& enable)
{

	// Executer our bit of code

	/*m_enabled = enable;

	if (enable)
	{
		StartTimers();
	}
	else
	{
		StopTimers();
	}*/
}