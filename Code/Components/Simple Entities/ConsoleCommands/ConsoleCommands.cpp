#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Simple Entities/ConsoleCommands/ConsoleCommands.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>

#include <CrySystem/ConsoleRegistration.h>
#include <CrySystem/ISystem.h>

static void RegisterConsoleCommands(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CConsoleCommands));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterConsoleCommands)


// The function that will be executed with the command, i think it needs to be a static function and not a member function
static void MyCommand(IConsoleCmdArgs* pArgs)
{
	// The first argument is always the name of the command
	const char* szCommand = pArgs->GetArg(0);

	if (szCommand != nullptr && szCommand[0] != '\0')
	{
	}

	if (pArgs->GetArgCount() > 1)
	{
		// Get the first argument, if any
		const char* szFirstArgument = pArgs->GetArg(1);

		if (szFirstArgument != nullptr && szFirstArgument[0] != '\0')
		{
			/* Handle the command, and its argument here */
		}
	}
}

void CConsoleCommands::Initialize()
{
	RegisterCommand();
}

void CConsoleCommands::RegisterCommand()
{
	// Specify bit flags that define the CCommand's behavior, see EVarFlags
	const int variableFlags = VF_NULL;

	// Register the command in the console
	REGISTER_COMMAND("myCommands", MyCommand, variableFlags, "Executes the MyCommand function!");
}

void CConsoleCommands::UnregisterCommand()
{
	// Make sure to unregister the command once we are done
	gEnv->pConsole->RemoveCommand("myCommand");
}