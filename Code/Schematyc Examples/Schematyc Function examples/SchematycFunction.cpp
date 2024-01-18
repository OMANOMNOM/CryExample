#include "StdAfx.h"
#include "Schematyc Examples/Schematyc Function examples/SchematycFunction.h"
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


// Include required for Schematyc function nodes 
#include <CrySchematyc/Env/Elements/EnvFunction.h>



// Makes the component 'editable' within the CE editor. 
static void RegisterSchematycFunction(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSchematycFunction));

		{
			// Here we reflect our Schematyc funciton node.
			auto const pFunction = SCHEMATYC_MAKE_ENV_FUNCTION(&CSchematycFunction::SetEnabled, "{2D222625-98F1-4605-ADE1-800245C6D924}"_cry_guid, "Set Enabled");
			pFunction->SetDescription("Controls whether the spawner is enabled during runtime.");
			pFunction->SetFlags({ Schematyc::EEnvFunctionFlags::Member });
			pFunction->BindInput(1, 'enab', "Enabled");
			componentScope.Register(pFunction);
		}
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterSchematycFunction)

/// <summary>
/// This is our example funciton that can use schematyc to call C++ code. 
/// </summary>
/// <param name="enable"></param>
void CSchematycFunction::SetEnabled(const bool& enable)
{

	 //Executer our bit of code
	if (enable)
	{
		CryLog("Schematyc has called a C++ funciton and the argument is true");
	}
	else
	{
		CryLog("Schematyc has called a C++ funciton and the argument is false");
	}
}